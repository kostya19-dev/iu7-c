#!/bin/bash




for file in *.c;
do 
  gcc -std=c99 -O0 -g -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -c "$file"
done

files=''

for file in *.o;
do
    files+="$file "
done

eval gcc -g -fsanitize=address -o app.exe "$files" -lm
