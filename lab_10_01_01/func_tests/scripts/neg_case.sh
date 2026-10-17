#!/bin/bash

if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <input_file> [args_file]"
    exit 1
fi

input_file=$1
args_file=$2

if [ -n "$args_file" ]; then
    args=$(cat "$args_file")
else
    args=""
fi

if ./app.exe $args < "$input_file" > /dev/null 2>&1; then
    exit 1
else
    exit 0
fi
