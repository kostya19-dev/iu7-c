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

if [ -z "$1" ] || ! [ -f "$1" ];
then
  exit 2
fi

if "$path_to_exe"/app.exe < "$1" > /dev/null 2>/dev/null;
then
  exit 0
fi
exit 1
