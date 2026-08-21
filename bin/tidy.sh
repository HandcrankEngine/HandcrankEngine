#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    cd "${SCRIPT_DIR}" || exit

    cd ..

    clang-tidy include/HandcrankEngine/*.hpp --header-filter='include/HandcrankEngine/.*'

)
