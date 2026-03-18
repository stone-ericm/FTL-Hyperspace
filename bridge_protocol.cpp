// bridge/bridge_protocol.cpp
#include "bridge_protocol.h"

#ifdef _WIN32
#include <cstdio>
#include <cstring>

namespace ftl_rl {

HANDLE create_pipe(const char* pipe_name) {
    HANDLE pipe = CreateNamedPipeA(
        pipe_name,
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
        1,            // max instances
        STATE_BUFFER_BYTES + MSG_HEADER_BYTES + 64,  // out buffer
        ACTION_BUFFER_BYTES + MSG_HEADER_BYTES + 64, // in buffer
        0,            // default timeout
        nullptr       // default security
    );
    if (pipe == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "[Bridge] CreateNamedPipe failed: %lu\n", GetLastError());
    }
    return pipe;
}

bool wait_for_connection(HANDLE pipe, int timeout_ms) {
    (void)timeout_ms;
    BOOL result = ConnectNamedPipe(pipe, nullptr);
    if (!result && GetLastError() != ERROR_PIPE_CONNECTED) {
        fprintf(stderr, "[Bridge] ConnectNamedPipe failed: %lu\n", GetLastError());
        return false;
    }
    return true;
}

// Write exactly n bytes to pipe. Returns true on success.
static bool write_all(HANDLE pipe, const void* data, uint32_t n) {
    const uint8_t* ptr = static_cast<const uint8_t*>(data);
    uint32_t written_total = 0;
    while (written_total < n) {
        DWORD written = 0;
        if (!WriteFile(pipe, ptr + written_total, n - written_total, &written, nullptr)) {
            fprintf(stderr, "[Bridge] WriteFile failed: %lu\n", GetLastError());
            return false;
        }
        written_total += written;
    }
    return true;
}

// Read exactly n bytes from pipe. Returns true on success.
static bool read_all(HANDLE pipe, void* data, uint32_t n, int timeout_ms) {
    uint8_t* ptr = static_cast<uint8_t*>(data);
    uint32_t read_total = 0;
    // TODO: For timeout support, use overlapped I/O or peek-based polling.
    // For MVP, this blocks indefinitely.
    (void)timeout_ms;
    while (read_total < n) {
        DWORD bytes_read = 0;
        if (!ReadFile(pipe, ptr + read_total, n - read_total, &bytes_read, nullptr)) {
            fprintf(stderr, "[Bridge] ReadFile failed: %lu\n", GetLastError());
            return false;
        }
        if (bytes_read == 0) return false; // pipe closed
        read_total += bytes_read;
    }
    return true;
}

bool send_message(HANDLE pipe, MsgType type, const void* payload, uint32_t payload_size) {
    uint8_t header[MSG_HEADER_BYTES];
    header[0] = static_cast<uint8_t>(type);
    memcpy(header + 1, &payload_size, sizeof(uint32_t)); // little-endian on x86
    if (!write_all(pipe, header, MSG_HEADER_BYTES)) return false;
    if (payload_size > 0 && payload != nullptr) {
        if (!write_all(pipe, payload, payload_size)) return false;
    }
    return true;
}

bool recv_message(HANDLE pipe, MsgType& out_type, void* out_payload,
                  uint32_t max_size, uint32_t& out_actual_size, int timeout_ms) {
    uint8_t header[MSG_HEADER_BYTES];
    if (!read_all(pipe, header, MSG_HEADER_BYTES, timeout_ms)) return false;

    out_type = static_cast<MsgType>(header[0]);
    uint32_t payload_size = 0;
    memcpy(&payload_size, header + 1, sizeof(uint32_t));
    out_actual_size = payload_size;

    if (payload_size > max_size) {
        fprintf(stderr, "[Bridge] Payload too large: %u > %u\n", payload_size, max_size);
        return false;
    }
    if (payload_size > 0) {
        if (!read_all(pipe, out_payload, payload_size, timeout_ms)) return false;
    }
    return true;
}

bool peek_pipe(HANDLE pipe, uint32_t& bytes_available) {
    DWORD avail = 0;
    if (!PeekNamedPipe(pipe, nullptr, 0, nullptr, &avail, nullptr)) {
        fprintf(stderr, "[Bridge] PeekNamedPipe failed: %lu\n", GetLastError());
        bytes_available = 0;
        return false;
    }
    bytes_available = static_cast<uint32_t>(avail);
    return true;
}

void close_pipe(HANDLE pipe) {
    if (pipe != INVALID_HANDLE_VALUE) {
        DisconnectNamedPipe(pipe);
        CloseHandle(pipe);
    }
}

} // namespace ftl_rl
#endif // _WIN32
