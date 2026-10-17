#!/bin/bash

gcc -std=c99 --coverage -O0 -Wall -Werror -Wpedantic -Wextra -o app.exe main.c io.c process.c -lm
