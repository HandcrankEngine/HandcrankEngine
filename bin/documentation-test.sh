#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

REDON=$(tput setaf 1)
GREENON=$(tput setaf 2)
COLOROFF=$(tput sgr0)

(

    cd "${SCRIPT_DIR}" || exit

    . find-sdl.sh

    cd ..

    printf "Running Documentation Tests\n"

    find ./documentation -type f -name "*.cpp" | while read -r FILE; do

        printf " - Running %s ... " "${FILE}"

        if ! g++ -std=c++17 -o test "${FILE}" -Iinclude \
            -I"${SDL_INCLUDE_PATH}" -L"${SDL_PATH}/lib" \
            -I"${SDL_IMAGE_INCLUDE_PATH}" -L"${SDL_IMAGE_PATH}/lib" \
            -I"${SDL_TTF_INCLUDE_PATH}" -L"${SDL_TTF_PATH}/lib" \
            -I"${SDL_MIXER_INCLUDE_PATH}" -L"${SDL_MIXER_PATH}/lib" \
            -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer; then
            printf "%sFAILED%s\n" "${REDON}" "${COLOROFF}"
            exit 1
        fi

        printf "%sOK%s\n" "${GREENON}" "${COLOROFF}"

        rm test

    done

)
