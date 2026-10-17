#!/bin/bash

files=''

for file in *.c;
do
    files+="$file "
done

eval gcc -std=c99 --coverage -O0 -Wall -Werror -Wpedantic -Wextra -o app.exe "$files" -lm
