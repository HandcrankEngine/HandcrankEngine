#!/bin/bash

REDON=$(tput setaf 1)
GREENON=$(tput setaf 2)
COLOROFF=$(tput sgr0)

printf "Running Unit Tests\n"

find ./tests -type f -name "*.cpp" | while read -r FILE; do

    printf "Running tests in %s ... " "${FILE}"

    g++ -std=c++17 -o test "${FILE}" -Iincludes

    if ./test; then
        printf "%sPASS%s\n" "${GREENON}" "${COLOROFF}"
    else
        printf "%FAIL%s\n" "${REDON}" "${COLOROFF}"
    fi

    rm test

done
