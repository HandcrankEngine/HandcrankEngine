#!/bin/bash

REDON=$(tput setaf 1)
GREENON=$(tput setaf 2)
COLOROFF=$(tput sgr0)

printf "Running Unit Tests\n"

find ./tests -type f -name "*.cpp" | while read -r FILE; do

    printf "Running tests in %s ... " "${FILE}"

    g++ -std=c++17 -o test "${FILE}" -Iincludes \
        -I/opt/homebrew/Cellar/sdl2/2.28.4/include/SDL2 -L/opt/homebrew/Cellar/sdl2/2.28.4/lib \
        -I/opt/homebrew/Cellar/sdl2_image/2.6.3_2/include/SDL2 -L/opt/homebrew/Cellar/sdl2_image/2.6.3_2/lib \
        -I/opt/homebrew/Cellar/sdl2_ttf/2.20.2/include/SDL2 -L/opt/homebrew/Cellar/sdl2_ttf/2.20.2/lib \
        -lSDL2 -lSDL2_image -lSDL2_ttf

    if ./test; then
        printf "%sPASS%s\n" "${GREENON}" "${COLOROFF}"
    else
        printf "%FAIL%s\n" "${REDON}" "${COLOROFF}"
    fi

    rm test

done
