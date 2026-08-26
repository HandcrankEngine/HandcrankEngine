#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    cd "${SCRIPT_DIR}" || exit

    cd ..

    [ -d "fonts" ] && find fonts -type f ! -name "*.h" -exec sh -c 'echo "#pragma once\n" > "${0%.*}.h" && xxd -i "$0" >> "${0%.*}.h"' {} \;
    [ -d "images" ] && find images -type f ! -name "*.h" -exec sh -c 'echo "#pragma once\n" > "${0%.*}.h" && xxd -i "$0" >> "${0%.*}.h"' {} \;
    [ -d "sfx" ] && find sfx -type f ! -name "*.h" -exec sh -c 'echo "#pragma once\n" > "${0%.*}.h" && xxd -i "$0" >> "${0%.*}.h"' {} \;

)
