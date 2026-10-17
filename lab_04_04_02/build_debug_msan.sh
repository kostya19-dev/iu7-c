#!/bin/bash

files=''

for file in *.c;
do
    files+="$file "
done

eval clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g "$files" -o app.exe
