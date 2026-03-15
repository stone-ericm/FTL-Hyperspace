// bridge/bridge_protocol.h
#pragma once

#include <cstdint>
#include <cstddef>

#ifdef _WIN32
#include <windows.h>
#else
// Stub for non-Windows compilation (Mac development)
typedef void* HANDLE;
#define INVALID_HANDLE_VALUE ((HANDLE)(long long)-1)
#endif

namespace ftl_rl {

// --- Constants ---
constexpr size_t OBS_FIELD_COUNT = 5793;
constexpr size_t ACTION_HEAD_COUNT = 85;
constexpr size_t STATE_BUFFER_BYTES = OBS_FIELD_COUNT * sizeof(float);    // 23,172
constexpr size_t ACTION_BUFFER_BYTES = ACTION_HEAD_COUNT * sizeof(int32_t); // 340
constexpr size_t MSG_HEADER_BYTES = 5; // 1 byte type + 4 bytes length

// --- Message Types ---
enum class MsgType : uint8_t {
    STATE        = 0x01,  // FTL → Python: float32[5793]
    ACTION       = 0x02,  // Python → FTL: int32[85]
    RESET        = 0x03,  // Python → FTL: (empty)
    RESET_ACK    = 0x04,  // FTL → Python: float32[5793] (initial state)
    EPISODE_DONE = 0x05,  // FTL → Python: uint8 (result)
};

// --- Episode Result ---
enum class EpisodeResult : uint8_t {
    LOSS = 0,
    WIN  = 1,
    FLED = 2,
};

// --- Protocol I/O ---

// Create named pipe server. Returns INVALID_HANDLE_VALUE on failure.
// pipe_name: e.g., "\\\\.\\pipe\\ftl_rl_0"
HANDLE create_pipe(const char* pipe_name);

// Wait for client connection. Blocks until connected or timeout.
// Returns true if client connected, false on timeout/error.
bool wait_for_connection(HANDLE pipe, int timeout_ms);

// Send a message. Returns true on success.
bool send_message(HANDLE pipe, MsgType type, const void* payload, uint32_t payload_size);

// Receive a message. Returns true on success.
// Sets out_type and copies payload into out_payload (up to max_size).
// Sets out_actual_size to actual payload bytes received.
bool recv_message(HANDLE pipe, MsgType& out_type, void* out_payload,
                  uint32_t max_size, uint32_t& out_actual_size, int timeout_ms);

// Close and cleanup pipe handle.
void close_pipe(HANDLE pipe);

// Non-blocking check for available data in pipe.
// Returns true if pipe is valid; sets bytes_available to buffered byte count.
// Returns false if pipe is broken (client disconnected).
bool peek_pipe(HANDLE pipe, uint32_t& bytes_available);

} // namespace ftl_rl
