#!/bin/bash

# Define the server and client executable names
SERVER="./server"
CLIENT="./client"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"

# List of test strings
TEST_STRINGS=(
"123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 "
)

# Start the server in the background and capture its PID
$SERVER &
SERVER_PID=$!

# Give the server a moment to start up
sleep 1

# Loop through each test string
for TEST_STRING in "${TEST_STRINGS[@]}"; do
    $CLIENT $SERVER_PID "$TEST_STRING"
	sleep 1
done

# Attempt to kill the server process after tests
kill $SERVER_PID

# Give it a moment to terminate
sleep 1

# Check if the server process is still running using pgrep
if pgrep -x "server" >/dev/null; then
    printf "\nFailed to kill the server process with PID %d.\n" "$SERVER_PID"
else
    printf "\nServer process with PID %d killed successfully.\n" "$SERVER_PID"
fi

echo "All tests complete."

