#!/bin/bash
# Build bridge DLL, deploy to Alienware, kill FTL, copy DLL, relaunch.
# Usage: ./scripts/deploy_and_launch.sh [--skip-build]

set -e

REPO_DIR="$(cd "$(dirname "$0")/.." && pwd)"
REMOTE="alienware"
FTL_DIR='C:\Program Files (x86)\Steam\steamapps\common\FTL Faster Than Light'
STAGING="C:\\Users\\stone\\ftl-rl"

# Build (unless --skip-build)
if [[ "$1" != "--skip-build" ]]; then
    echo "=== Building DLL ==="
    docker run --rm -v "$REPO_DIR:/ftl" \
        ghcr.io/ftl-hyperspace/hs-devcontainer \
        bash -c "cd /ftl && ninja -C build-windows-release 2>&1 | tail -3"
fi

# Kill FTL
echo "=== Killing FTL ==="
ssh -o ConnectTimeout=5 "$REMOTE" "taskkill /IM FTLGame.exe /F 2>nul" 2>&1 || true
sleep 1

# Deploy DLL
echo "=== Deploying DLL ==="
scp "$REPO_DIR/build-windows-release/Hyperspace.dll" \
    "$REMOTE:ftl-rl/Hyperspace_bridge.dll" 2>/dev/null
ssh -o ConnectTimeout=5 "$REMOTE" \
    "copy /Y ${STAGING}\\Hyperspace_bridge.dll \"${FTL_DIR}\\Hyperspace.dll\"" 2>&1

# Launch FTL via scheduled task (runs in interactive desktop session)
echo "=== Launching FTL ==="
ssh -o ConnectTimeout=5 "$REMOTE" "schtasks /run /tn \"LaunchFTL\" 2>&1" 2>&1

echo "=== Done. FTL should be starting. ==="
