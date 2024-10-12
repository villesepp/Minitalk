#!/bin/bash

SERVER="./server"
CLIENT="./client"

# Start the server in the background and capture its PID
$SERVER &
SERVER_PID=$!

sleep 1
$CLIENT $SERVER_PID "123456789"
sleep 1
kill $SERVER_PID
sleep 1

# Check if the server process is still running using pgrep
if pgrep -x "server" >/dev/null; then
    printf "\nFailed to kill the server process with PID %d.\n" "$SERVER_PID"
else
    printf "\nServer process with PID %d killed successfully.\n" "$SERVER_PID"
fi
