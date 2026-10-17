#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] || ! [ -f "$2" ] || ! [ -f "$2" ];
then
  exit 2
fi

if diff <(grep -E '[0-9a-zAZ ]+' "$1") <(grep -E '[0-9a-zAZ ]+' "$2") > /dev/null 2>/dev/null; then
exit 0
fi
exit 1

