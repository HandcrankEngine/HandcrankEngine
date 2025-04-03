#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    cd "${SCRIPT_DIR}" || exit

    cd ..

    [ -d "fonts" ] && find fonts -type f -name "*.ttf" -exec sh -c 'echo "#pragma once\n" > "${0%.ttf}.h" && xxd -i "$0" >> "${0%.ttf}.h"' {} \;
    [ -d "fonts" ] && find images -type f -name "*.png" -exec sh -c 'echo "#pragma once\n" > "${0%.png}.h" && xxd -i "$0" >> "${0%.png}.h"' {} \;

)
