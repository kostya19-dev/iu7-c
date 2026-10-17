#!/bin/bash

echo "Сборка с адресным санитайзером"
./build_debug_asan.sh
./func_tests/scripts/func_tests.sh
echo "------------------------------"
echo
echo "Сборка с санитайзером памяти"
./build_debug_msan.sh
./func_tests/scripts/func_tests.sh
echo "------------------------------"
echo
echo "Сборка с санитайзером неопределённого поведения"
./build_debug_ubsan.sh
./func_tests/scripts/func_tests.sh
