#!/bin/bash

if [ -d "/opt/homebrew/Cellar/sdl2/2.30.10" ]; then
    export SDL2_PATH="/opt/homebrew/Cellar/sdl2/2.30.10"
elif [ -d "/tmp/.sdl/SDL2-2.30.10" ]; then
    export SDL2_PATH="/tmp/.sdl/SDL2-2.30.10"
else
    echo "SDL2 not found!"

    exit 1
fi

if [ -d "/opt/homebrew/Cellar/sdl2_image/2.8.3" ]; then
    export SDL2_IMAGE_PATH="/opt/homebrew/Cellar/sdl2_image/2.8.3"
elif [ -d "/tmp/.sdl/SDL2_image-2.8.3" ]; then
    export SDL2_IMAGE_PATH="/tmp/.sdl/SDL2_image-2.8.3"
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
