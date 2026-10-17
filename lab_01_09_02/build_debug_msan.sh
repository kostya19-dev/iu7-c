#!/bin/bash

clang -std=c99 -Wall -g -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer main.c -o app.exe
