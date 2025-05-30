#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    mkdir -p build/web

    emcc -std=c++17 -o build/web/index.html src/*.cpp -Ifonts -Iimages -Iinclude -Iexamples -Isrc \
        -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -s USE_SDL_TTF=2 \
        --shell-file templates/web-minimal.html

)
