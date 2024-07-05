#!/bin/bash

if [ -d "/opt/homebrew/Cellar/sdl2/2.30.4" ]; then
    export SDL2_PATH="/opt/homebrew/Cellar/sdl2/2.30.4"
elif [ -d "/tmp/.sdl/SDL2-2.30.4" ]; then
    export SDL2_PATH="/tmp/.sdl/SDL2-2.30.4"
else
    echo "SDL2 not found!"

    exit 1
fi

if [ -d "/opt/homebrew/Cellar/sdl2_image/2.8.2_1" ]; then
    export SDL2_IMAGE_PATH="/opt/homebrew/Cellar/sdl2_image/2.8.2_1"
elif [ -d "/tmp/.sdl/SDL2_image-2.8.2" ]; then
    export SDL2_IMAGE_PATH="/tmp/.sdl/SDL2_image-2.8.2"
else
    echo "SDL2_image not found!"

    exit 1
fi

if [ -d "/opt/homebrew/Cellar/sdl2_ttf/2.22.0" ]; then
    export SDL2_TTF_PATH="/opt/homebrew/Cellar/sdl2_ttf/2.22.0"
elif [ -d "/tmp/.sdl/SDL2_ttf-2.22.0" ]; then
    export SDL2_TTF_PATH="/tmp/.sdl/SDL2_ttf-2.22.0"
else
    echo "SDL2_ttf not found!"

    exit 1
fi
