#!/bin/bash

if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <input_file> <expected_output_file> [args_file]"
    exit 1
fi

input_file=$1
expected_output_file=$2
args_file=$3

output_file=$(mktemp)

if [ -n "$args_file" ]; then
    args=$(cat "$args_file")
else
    args=""
fi

if ! ./app.exe $args < "$input_file" > "$output_file"; then
    rm -f "$output_file"
    exit 1
fi

if diff -q "$output_file" "$expected_output_file" > /dev/null; then
    rm -f "$output_file"
    exit 0
else
    rm -f "$output_file"
    exit 1
fi
