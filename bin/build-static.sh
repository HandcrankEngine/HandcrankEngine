#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    mkdir -p build/

    cd "${SCRIPT_DIR}" || exit

    . find-sdl.sh

    cd ..

    g++ -std=c++17 -o build/handcrank-engine src/*.cpp -Ifonts -Iimages -Iinclude -Iexamples -Isrc \
        -I"${SDL3_PATH}/include" -L"${SDL3_PATH}/lib" \
        -I"${SDL3_IMAGE_PATH}/include" -L"${SDL3_IMAGE_PATH}/lib" \
        -I"${SDL3_TTF_PATH}/include" -L"${SDL3_TTF_PATH}/lib" \
        -lSDL3 -lSDL3_image -lSDL3_ttf \
        -static

)
