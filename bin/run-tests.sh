#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

REDON=$(tput setaf 1)
GREENON=$(tput setaf 2)
COLOROFF=$(tput sgr0)

(

    cd "${SCRIPT_DIR}" || exit

    . find-sdl.sh

    cd ..

    printf "Running Unit Tests\n"

    find ./tests -type f -name "*.cpp" | while read -r FILE; do

        printf "Running tests in %s ... " "${FILE}"

        g++ -std=c++17 -o test "${FILE}" -Iincludes \
            -I"${SDL2_PATH}/include/SDL2" -L"${SDL2_PATH}/lib" \
            -I"${SDL2_IMAGE_PATH}/include/SDL2" -L"${SDL2_IMAGE_PATH}/lib" \
            -I"${SDL2_TTF_PATH}/include/SDL2" -L"${SDL2_TTF_PATH}/lib" \
            -lSDL2

        if ./test; then
            printf "%sPASS%s\n" "${GREENON}" "${COLOROFF}"
        else
            printf "%FAIL%s\n" "${REDON}" "${COLOROFF}"
        fi

        rm test

    done

)
