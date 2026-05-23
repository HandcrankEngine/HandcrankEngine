#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    mkdir -p /tmp/dist/web

    emcc -std=c++17 -Os -o /tmp/dist/web/index.html src/*.cpp -Ifonts -Iimages -Iinclude -Iexamples -Isrc \
        -I"${DEPS_PREFIX}"/include/SDL2 -I"${DEPS_PREFIX}"/include -L"${DEPS_PREFIX}"/lib \
        -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer \
        -s USE_FREETYPE=1 -s USE_HARFBUZZ=1 \
        -s MAX_WEBGL_VERSION=2 \
        --shell-file templates/web-minimal.html

    gzip -k /tmp/dist/web/index.wasm

)
