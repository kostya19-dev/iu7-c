#!/bin/bash

pos_errors=0
echo "Позитивные тесты"
while IFS= read -r pos_in; do
  "$(dirname "$0")"/pos_case.sh "$pos_in" "${pos_in/in/out}"
  test_code=$?
  if [[ $test_code == 128 ]]; then
    echo "Тест $(basename "$pos_in") не был произведён из-за ошибки"
    ((pos_errors++))
  elif [[ $test_code == 129 ]]; then
    echo "Тест $(basename "$pos_in") провален"
    ((pos_errors++))
  elif [[ $test_code != 0 ]]; then
    echo "Тест $(basename "$pos_in") провален. Программа завершилась с кодом $test_code."
    ((pos_errors++))
  else
    echo "Тест $(basename "$pos_in") пройден"
  fi
 
done < <(find "$(dirname "$0")"/../data -type f -name "pos*in.txt" | sort)

echo
echo "Негативные тесты"
neg_errors=0
while IFS= read -r neg_in; do
  "$(dirname "$0")"/neg_case.sh "$neg_in" > /dev/null 2>/dev/null
  test_code=$?
  
  if [[ $test_code == 2 ]]; then
    echo "Тест $(basename "$neg_in") не был произведён из-за ошибки"
    ((neg_errors++))
  elif [[ $test_code == 1 ]]; then
    echo "Тест $(basename "$neg_in") пройден"
  else
    echo "Тест $(basename "$neg_in") провален"
    ((neg_errors++))
  fi
  
done < <(find "$(dirname "$0")"/../data -type f -name "neg*in.txt" | sort)

echo
echo "Результат:"
echo "позитивных тестов провалено: $pos_errors;"
echo "негативных тестов провалено: $neg_errors."

exit $((pos_errors + neg_errors))
