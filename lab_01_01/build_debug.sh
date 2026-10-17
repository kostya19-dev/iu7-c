#!/bin/bash

gcc -std=c99 -O0 -g -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -c main.c

gcc -o app.exe main.o -lm 
