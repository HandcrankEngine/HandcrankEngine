#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    rm -rf build/web

    mkdir -p build/web

    emcc -std=c++17 -Os -o build/web/index.html src/*.cpp -Ifonts -Iimages -Iinclude -Iexamples -Isrc \
        -s USE_SDL=3 -s USE_SDL_IMAGE=3 -s SDL3_IMAGE_FORMATS='["png", "svg"]' -s USE_SDL_TTF=3 -s USE_SDL_MIXER=2 \
        --shell-file templates/web-minimal.html

    gzip -k build/web/index.wasm

)
