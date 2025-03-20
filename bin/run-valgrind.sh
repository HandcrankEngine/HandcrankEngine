#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    cd "${SCRIPT_DIR}" || exit

    cd ..

    ./bin/build-static.sh

    valgrind --leak-check=yes --track-origins=yes build/handcrank-engine

)
