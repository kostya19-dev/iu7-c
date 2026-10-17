#!/bin/bash

gcc -std=c99 -O2 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -c main.c io.c process.c

gcc -O2 -o app.exe main.o io.o process.o -lm
