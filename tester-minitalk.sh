#!/bin/bash

# Define the server and client executable names
SERVER="./server"
CLIENT="./client"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"

# List of test strings
TEST_STRINGS=(
""
"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."

"Phasellus eget consectetur justo. Aliquam sit amet feugiat tellus, a dictum est. Cras sapien purus, consequat at felis et, fermentum pharetra risus. Proin interdum quis tortor quis sodales. Sed vel libero maximus, pellentesque nibh consequat, sodales lorem. Integer ullamcorper ac nisi vel commodo. Praesent elementum, justo id varius aliquam, ante diam fringilla nunc, eget vehicula augue justo non nisi. Quisque massa magna, cursus ut pellentesque vitae, maximus a massa. Nunc velit purus, venenatis eget dignissim a, tempus in nibh. In porttitor dapibus sem, non ultrices lectus. Suspendisse mattis congue lectus, bibendum commodo ante.

Donec tempus tempus accumsan. Aenean consectetur felis sapien. Donec faucibus, tortor vitae vulputate interdum, ipsum sem eleifend ligula, sed accumsan ligula tellus eget ex. In vestibulum et est quis posuere. Donec aliquet imperdiet erat, nec vehicula nisl convallis a. Sed semper turpis eu magna aliquet, blandit pellentesque nisi facilisis. Donec suscipit ipsum nibh, nec fermentum lorem feugiat quis. Phasellus nec ipsum ultricies, accumsan libero at, commodo magna. Donec dapibus, metus ut vulputate pulvinar, ex erat pulvinar orci, et condimentum nulla lacus ornare massa. Nulla in risus dui. Ut volutpat, eros ut aliquam sagittis, sem ante vestibulum neque, ac aliquam quam libero id magna."
)

# Start the server in the background and capture its PID
$SERVER &
SERVER_PID=$!

# Give the server a moment to start up
sleep 1

# Print the server PID
echo "Server started with PID: $SERVER_PID"

# Loop through each test string
for TEST_STRING in "${TEST_STRINGS[@]}"; do
    printf "Sending message: %s \n" "$TEST_STRING"
    printf "Printed message: "
    $CLIENT $SERVER_PID "$TEST_STRING"
	sleep 1
    printf "\n"
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

