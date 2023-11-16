#!/bin/bash

if [ -d "/opt/homebrew/Cellar/sdl2/2.28.5" ]; then
    export SDL2_PATH="/opt/homebrew/Cellar/sdl2/2.28.5"
elif [ -d "/tmp/.sdl/SDL2-2.28.5" ]; then
    export SDL2_PATH="/tmp/.sdl/SDL2-2.28.5"
else
    echo "SDL2 not found!"

    exit 1
fi

if [ -d "/opt/homebrew/Cellar/sdl2_image/2.6.3_2" ]; then
    export SDL2_IMAGE_PATH="/opt/homebrew/Cellar/sdl2_image/2.6.3_2"
elif [ -d "/tmp/.sdl/SDL2_image-2.6.3" ]; then
    export SDL2_IMAGE_PATH="/tmp/.sdl/SDL2_image-2.6.3"
else
    echo "SDL2_image not found!"

    exit 1
fi

if [ -d "/opt/homebrew/Cellar/sdl2_ttf/2.20.2" ]; then
    export SDL2_TTF_PATH="/opt/homebrew/Cellar/sdl2_ttf/2.20.2"
elif [ -d "/tmp/.sdl/SDL2_ttf-2.20.2" ]; then
    export SDL2_TTF_PATH="/tmp/.sdl/SDL2_ttf-2.20.2"
else
    echo "SDL2_ttf not found!"

    exit 1
fi
