#!/bin/bash

for file in *.c;
do 
    gcc -std=c99 -Wall -Werror -O2 -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -c "$file"
done

files=''

for file in *.o;
do
    files+="$file "
done

eval gcc -o app.exe "$files"
