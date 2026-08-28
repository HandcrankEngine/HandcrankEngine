#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    cd "${SCRIPT_DIR}" || exit

    cd ..

    for DIR in fonts images sfx; do
        [ -d "${DIR}" ] && find "${DIR}" -type f ! -name "*.h" -exec sh -c 'printf "#pragma once\n\n%s\n" "$(xxd -i "$0")" > "${0%.*}.h"' {} \;
    done

)
