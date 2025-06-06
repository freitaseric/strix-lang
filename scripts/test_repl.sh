#!/bin/bash

# --- Setting Up ---
REPL_EXECUTABLE="scripts/repl.sh"
EXPECTED_EXIT_MESSAGE="Exiting Strix..."
TEMP_OUTPUT_FILE="repl_output.tmp"

# --- Cleaning Function ---
cleanup() {
  echo "Cleaning temp files..."
  rm -f "$TEMP_OUTPUT_FILE"
}
trap cleanup EXIT

# --- Execution and Test ---
echo "Starting REPL test..."

if command -v expect &> /dev/null; then
  echo "Using 'expect' to interact with the REPL."

  cat > expect_script.exp <<EOF
spawn $REPL_EXECUTABLE
send ".exit\r"
expect "$EXPECTED_EXIT_MESSAGE"
expect eof
EOF

  expect -f expect_script.exp > "$TEMP_OUTPUT_FILE"
  REPL_EXIT_CODE=$?
else
  echo "WARNING: 'expect' not found."
  exit 1
fi

# --- Verify ---
echo "--- REPL output ($TEMP_OUTPUT_FILE) ---"
cat "$TEMP_OUTPUT_FILE"
echo "------------------------------------"
echo "REPL exit code: $REPL_EXIT_CODE"

if grep -q "$EXPECTED_EXIT_MESSAGE" "$TEMP_OUTPUT_FILE"; then
  echo "SUCCESS: Expected output message found!"
else
  echo "FAIL: Expected output message not found"
  exit 1
fi

if [ "$REPL_EXIT_CODE" -eq 0 ]; then
  echo "SUCCESS: REPL (or test command) terminated with exit code 0. "
else
  echo "FAILURE: REPL (or test command) terminated with exit code $REPL_EXIT_CODE. "
  exit 1
fi

echo "REPL test completed successfully! "
exit 0
