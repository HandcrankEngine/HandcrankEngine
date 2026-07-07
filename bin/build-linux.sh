#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    mkdir -p build/

    cd "${SCRIPT_DIR}" || exit

    cd ..

    g++ -std=c++17 -o build/handcrank-engine src/*.cpp -Ifonts -Iimages -Iinclude -Iexamples -Isrc \
        -lSDL3 -lSDL3_image -lSDL3_ttf -lSDL3_mixer

)
