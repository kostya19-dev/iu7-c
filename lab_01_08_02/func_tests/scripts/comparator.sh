#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] || ! [ -f "$2" ] || ! [ -f "$2" ];
then
  exit 2
fi

file1=$(cat "$1")
file2=$(cat "$2")

if  diff <(sed '1 s/.*Result: //' <(grep -E '.*Result: ' -A "$(echo "$file1" | wc -l)" <(echo "$file1"))) <(sed '1 s/.*Result: //' <(grep -E '.*Result: ' -A "$(echo "$file2" | wc -l)" <(echo "$file2"))) > /dev/null 2>/dev/null; then
exit 0
fi
exit 1

