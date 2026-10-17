#!/bin/bash


gcc -std=c99 -O0 -g -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -c main.c

gcc -g -fsanitize=undefined -o app.exe main.o -lm 
