#!/bin/bash

./build_coverage.sh

while IFS= read -r in;
do
  ./app.exe < "$in" > /dev/null 2>/dev/null
done < <(find func_tests/data -type f -name "*in.txt")

gcov app-main.gcno | grep -m 1 %  
