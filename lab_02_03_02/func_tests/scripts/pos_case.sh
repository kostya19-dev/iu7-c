#!/bin/bash

if [ -f ./app.exe ]; 
then
  path_to_exe="."
elif [ -f ../app.exe ];
then
  path_to_exe=".."
elif [ -f ../../app.exe ];
then
  path_to_exe="../.."
fi 

if [ -z "$1" ] || [ -z "$2" ] || ! [ -f "$1" ] || ! [ -f "$2" ];
then
  exit 128
fi

"$path_to_exe"/app.exe < "$1" > /dev/null 2>/dev/null;
code_ret=$?


if [[ $code_ret != 0 ]]; then
  exit $code_ret
fi

if "$path_to_exe"/func_tests/scripts/comparator.sh <("$path_to_exe"/app.exe < "$1") "$2" > /dev/null 2>/dev/null;
then
  exit 0
fi
exit 129 

