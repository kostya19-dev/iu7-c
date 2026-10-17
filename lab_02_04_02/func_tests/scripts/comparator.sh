#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] || ! [ -f "$2" ] || ! [ -f "$2" ];
then
  exit 2
fi

diff <(grep -oE '[+-]?[0-9]+(\.[0-9]+)?' "$1") <(grep -oE '[+-]?[0-9]+(\.[0-9]+)?' "$2") > /dev/null 2>/dev/null
code=$?

if [[ $code == 100 ]]; then
  exit 0
elif [[ $code == 0 ]]; then
  exit 0
fi
exit 1
