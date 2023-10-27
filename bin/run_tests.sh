#!/bin/bash

find ./tests -type f -name "*.cpp" | while read -r FILE; do

    printf "Running tests in %s ..." "${FILE}"

    g++ -std=c++17 -o test "${FILE}" -Iincludes

    if ./test; then
        echo "PASS"
    else
        echo "FAIL"
    fi

    rm test

done
