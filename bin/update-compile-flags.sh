#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    mkdir -p build/

    cd "${SCRIPT_DIR}" || exit

    . find-sdl.sh

    cd ..

    cat > "compile_flags.txt" << EOF
-std=c++17
-I${SDL3_PATH}/include
-I${SDL3_IMAGE_PATH}/include
-I${SDL3_TTF_PATH}/include
EOF

)
