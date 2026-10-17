#!/bin/bash

RESET='\033[0m'
RED='\033[1;31m'
GREEN='\033[1;32m'

count_errors=0
count_tests=0

valgrind="0"
if [ "$1" == "--valgrind" ]; then
    valgrind="1"
fi

run_test() {
    local test_type=$1
    local file_in=$2
    local number=$3
    local file_out="./func_tests/data/${test_type}_${number}_out.txt"
    local file_args="./func_tests/data/${test_type}_${number}_args.txt"

    local command="./func_tests/scripts/${test_type}_case.sh $file_in $file_out"
    [ -f "$file_args" ] && command="$command $file_args"

    $command
    local error=$?

    count_tests=$((count_tests + 1))
    if [ "$valgrind" == "1" ]; then
        case $error in
            0) echo -e "${test_type^^}_${number}: ${GREEN}PASSED${RESET} ==<--->== Memory: ${GREEN}PASSED${RESET}" ;;
            1) echo -e "${test_type^^}_${number}: ${RED}FAILED${RESET} ==<--->== Memory: ${GREEN}PASSED${RESET}" ; count_errors=$((count_errors + 1)) ;;
            2) echo -e "${test_type^^}_${number}: ${GREEN}PASSED${RESET} ==<--->== Memory: ${RED}FAILED${RESET}" ; count_errors=$((count_errors + 1)) ;;
            3) echo -e "${test_type^^}_${number}: ${RED}FAILED${RESET} ==<--->== Memory: ${RED}FAILED${RESET}" ; count_errors=$((count_errors + 1)) ;;
        esac
    else
        case $error in
            0) echo -e "${test_type^^}_${number}: ${GREEN}PASSED${RESET}" ;;
            *) echo -e "${test_type^^}_${number}: ${RED}FAILED${RESET}" ; count_errors=$((count_errors + 1)) ;;
        esac
    fi
}

process_tests() {
    local test_type=$1
    local files="./func_tests/data/${test_type}_??_in.txt"

    for file_in in $files; do
        local number=$(echo "$file_in" | grep -o "[0-9]*")
        [ -z "$number" ] && continue
        run_test "$test_type" "$file_in" "$number"
    done
}

process_tests "pos"
process_tests "neg"

echo "Total tests: $count_tests"
if [ "$count_errors" -eq 0 ]; then
    echo -e "${GREEN}All tests passed.${RESET}"
else
    echo -e "${RED}Failed $count_errors tests.${RESET}"
fi

exit $count_errors
