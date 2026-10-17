#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] || ! [ -f "$2" ] || ! [ -f "$2" ];
then
  exit 2
fi

if  diff <(grep -oE '[a-zA-Z]*' "$1") <(grep -oE '[a-zA-Z]*' "$2") > /dev/null 2>/dev/null; then
exit 0
fi
exit 1

