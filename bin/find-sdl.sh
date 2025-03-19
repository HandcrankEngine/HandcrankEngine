#!/bin/bash

[[ ! -d "${SDL3_PATH}" && -d "/opt/homebrew/Cellar/sdl3" ]] &&
    export SDL3_PATH=$(find /opt/homebrew/Cellar/sdl3 -name "3.*" -type d | head -n 1)
[[ ! -d "${SDL3_PATH}" && -d "/tmp/.sdl/" ]] &&
    export SDL3_PATH=$(find /tmp/.sdl/ -name "SDL3-3.*" -type d | head -n 1)

[ ! -d "${SDL3_PATH}" ] && echo "SDL3 not found!" && exit 1

echo "SDL3 found at ${SDL3_PATH}"

[[ ! -d "${SDL3_IMAGE_PATH}" && -d "/opt/homebrew/Cellar/sdl3_image" ]] &&
    export SDL3_IMAGE_PATH=$(find /opt/homebrew/Cellar/sdl3_image -name "3.*" -type d | head -n 1)
[[ ! -d "${SDL3_IMAGE_PATH}" && -d "/tmp/.sdl/" ]] &&
    export SDL3_IMAGE_PATH=$(find /tmp/.sdl/ -name "SDL3_image-3.*" -type d | head -n 1)

[ ! -d "${SDL3_IMAGE_PATH}" ] && echo "SDL3_image not found!" && exit 1

echo "SDL3_image found at ${SDL3_IMAGE_PATH}"

[[ ! -d "${SDL3_TTF_PATH}" && -d "/opt/homebrew/Cellar/sdl3_ttf" ]] &&
    export SDL3_TTF_PATH=$(find /opt/homebrew/Cellar/sdl3_ttf -name "3.*" -type d | head -n 1)
[[ ! -d "${SDL3_TTF_PATH}" && -d "/tmp/.sdl/" ]] &&
    export SDL3_TTF_PATH=$(find /tmp/.sdl/ -name "SDL3_ttf-3.*" -type d | head -n 1)

[ ! -d "${SDL3_TTF_PATH}" ] && echo "SDL3_ttf not found!" && exit 1

echo "SDL3_ttf found at ${SDL3_TTF_PATH}"
