#!/bin/bash

REDON=$(tput setaf 1)
GREENON=$(tput setaf 2)
COLOROFF=$(tput sgr0)

printf "Running Unit Tests\n"

SDL2_PATH=""

if [ -d "/opt/homebrew/Cellar/sdl2/2.28.4" ]; then
    SDL2_PATH="/opt/homebrew/Cellar/sdl2/2.28.4"
elif [ -d "/tmp/.sdl/SDL2-2.28.4" ]; then
    SDL2_PATH="/tmp/.sdl/SDL2-2.28.4"
else
    echo "SDL2 not found!"

    exit 1
fi

find ./tests -type f -name "*.cpp" | while read -r FILE; do

    printf "Running tests in %s ... " "${FILE}"

    g++ -std=c++17 -o test "${FILE}" -Iincludes \
        -I"${SDL2_PATH}/include/SDL2" -L"${SDL2_PATH}/lib" \
        -lSDL2

    if ./test; then
        printf "%sPASS%s\n" "${GREENON}" "${COLOROFF}"
    else
        printf "%FAIL%s\n" "${REDON}" "${COLOROFF}"
    fi

    rm test

done
