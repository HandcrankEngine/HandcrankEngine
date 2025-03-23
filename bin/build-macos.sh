#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    mkdir -p build/

    cd "${SCRIPT_DIR}" || exit

    . find-sdl.sh

    cd ..

    APP_NAME="handcrank-engine"
    BUNDLE_ID="com.handcrankengine.handcrank-engine"
    VERSION="1.0"

    CONTENTS="build/${APP_NAME}.app/Contents"
    MACOS="${CONTENTS}/MacOS"
    FRAMEWORKS="${CONTENTS}/Frameworks"
    RESOURCES="${CONTENTS}/Resources"

    g++ -std=c++17 -o "build/${APP_NAME}" src/*.cpp -Ifonts -Iimages -Iinclude -Iexamples -Isrc \
        -I"${SDL2_PATH}/include/SDL2" -L"${SDL2_PATH}/lib" \
        -I"${SDL2_IMAGE_PATH}/include/SDL2" -L"${SDL2_IMAGE_PATH}/lib" \
        -I"${SDL2_TTF_PATH}/include/SDL2" -L"${SDL2_TTF_PATH}/lib" \
        -lSDL2 -lSDL2_image -lSDL2_ttf

    mkdir -p "${MACOS}"
    mkdir -p "${FRAMEWORKS}"
    mkdir -p "${RESOURCES}"

    chmod -R 755 "${CONTENTS}"

    cp "build/${APP_NAME}" "${MACOS}/"
    # chmod +x "${MACOS}/${APP_NAME}"

    cp "${SDL2_PATH}/lib/libSDL2.dylib" "${FRAMEWORKS}"
    cp "${SDL2_IMAGE_PATH}/lib/libSDL2_image.dylib" "${FRAMEWORKS}"
    cp "${SDL2_TTF_PATH}/lib/libSDL2_ttf.dylib" "${FRAMEWORKS}"
    # chmod +x "${FRAMEWORKS}"/*.dylib

    install_name_tool -change @rpath/libSDL2.dylib @executable_path/../Frameworks/libSDL2.dylib "${MACOS}/${APP_NAME}"
    install_name_tool -change @rpath/libSDL2_image.dylib @executable_path/../Frameworks/libSDL2_image.dylib "${MACOS}/${APP_NAME}"
    install_name_tool -change @rpath/libSDL2_ttf.dylib @executable_path/../Frameworks/libSDL2_ttf.dylib "${MACOS}/${APP_NAME}"

    install_name_tool -change @rpath/libSDL2.dylib @executable_path/../Frameworks/libSDL2.dylib "${FRAMEWORKS}/libSDL2_image.dylib"
    install_name_tool -change @rpath/libSDL2.dylib @executable_path/../Frameworks/libSDL2.dylib "${FRAMEWORKS}/libSDL2_ttf.dylib"

    cat > "${CONTENTS}/Info.plist" << EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleDevelopmentRegion</key>
    <string>English</string>
    <key>CFBundleExecutable</key>
    <string>${APP_NAME}</string>
    <key>CFBundleIconFile</key>
    <string>icon.icns</string>
    <key>CFBundleIdentifier</key>
    <string>${BUNDLE_ID}</string>
    <key>CFBundleInfoDictionaryVersion</key>
    <string>6.0</string>
    <key>CFBundleName</key>
    <string>${APP_NAME}</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleShortVersionString</key>
    <string>${VERSION}</string>
    <key>CFBundleVersion</key>
    <string>1</string>
    <key>NSHighResolutionCapable</key>
    <true/>
</dict>
</plist>
EOF

    hdiutil create -volname "${APP_NAME}" -srcfolder "build/${APP_NAME}.app" -ov -format UDZO "build/${APP_NAME}.dmg"

)
