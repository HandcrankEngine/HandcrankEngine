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

        printf " - Running %s " "${FILE}"

        if ! g++ -std=c++17 -o test "${FILE}" -Iinclude \
            -I"${SDL_INCLUDE_PATH}" -L"${SDL_PATH}/lib" \
            -I"${SDL_IMAGE_INCLUDE_PATH}" -L"${SDL_IMAGE_PATH}/lib" \
            -I"${SDL_TTF_INCLUDE_PATH}" -L"${SDL_TTF_PATH}/lib" \
            -I"${SDL_MIXER_INCLUDE_PATH}" -L"${SDL_MIXER_PATH}/lib" \
            -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer; then
            printf "%sCOMPILATION FAILED%s\n" "${REDON}" "${COLOROFF}"
            exit 1
        fi

        if ./test; then
            printf "%s PASS%s\n" "${GREENON}" "${COLOROFF}"
        else
            printf "%s FAIL%s\n" "${REDON}" "${COLOROFF}"
        fi

        rm test

    done

)
