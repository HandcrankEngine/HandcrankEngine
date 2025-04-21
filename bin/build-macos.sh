#!/bin/bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

(

    mkdir -p build/

    cd "${SCRIPT_DIR}" || exit

    . find-sdl.sh

    cd ..

    # CFBundleExecutable
    MACOSX_BUNDLE_EXECUTABLE_NAME="handcrank-engine"
    # CFBundleGetInfoString
    MACOSX_BUNDLE_INFO_STRING=""
    # CFBundleIconFile
    MACOSX_BUNDLE_ICON_FILE="icon.icns"
    # CFBundleIdentifier
    MACOSX_BUNDLE_GUI_IDENTIFIER="com.handcrankengine.demo"
    # CFBundleLongVersionString
    MACOSX_BUNDLE_LONG_VERSION_STRING="1.0"
    # CFBundleName
    MACOSX_BUNDLE_BUNDLE_NAME="handcrank-engine"
    # CFBundleShortVersionString
    MACOSX_BUNDLE_SHORT_VERSION_STRING="1.0"
    # CFBundleVersion
    MACOSX_BUNDLE_BUNDLE_VERSION="1.0"
    # NSHumanReadableCopyright
    MACOSX_BUNDLE_COPYRIGHT="Copyright (c) Scott Doxey. All Rights Reserved."

    CONTENTS="build/${MACOSX_BUNDLE_EXECUTABLE_NAME}.app/Contents"
    MACOS="${CONTENTS}/MacOS"
    FRAMEWORKS="${CONTENTS}/Frameworks"
    RESOURCES="${CONTENTS}/Resources"

    g++ -std=c++17 -o "build/${MACOSX_BUNDLE_EXECUTABLE_NAME}" src/*.cpp -Ifonts -Iimages -Iinclude -Iexamples -Isrc \
        -I"${SDL2_PATH}/include/SDL2" -L"${SDL2_PATH}/lib" \
        -I"${SDL2_IMAGE_PATH}/include/SDL2" -L"${SDL2_IMAGE_PATH}/lib" \
        -I"${SDL2_TTF_PATH}/include/SDL2" -L"${SDL2_TTF_PATH}/lib" \
        -lSDL2 -lSDL2_image -lSDL2_ttf

    mkdir -p "${MACOS}"
    mkdir -p "${FRAMEWORKS}"
    mkdir -p "${RESOURCES}"

    chmod -R 755 "${CONTENTS}"

    cp "build/${MACOSX_BUNDLE_EXECUTABLE_NAME}" "${MACOS}/"
    # chmod +x "${MACOS}/${MACOSX_BUNDLE_EXECUTABLE_NAME}"

    cp "resources/${MACOSX_BUNDLE_ICON_FILE}" "${RESOURCES}"

    cp "${SDL2_PATH}/lib/libSDL2.dylib" "${FRAMEWORKS}"
    cp "${SDL2_IMAGE_PATH}/lib/libSDL2_image.dylib" "${FRAMEWORKS}"
    cp "${SDL2_TTF_PATH}/lib/libSDL2_ttf.dylib" "${FRAMEWORKS}"
    # chmod +x "${FRAMEWORKS}"/*.dylib

    install_name_tool -change @rpath/libSDL2.dylib @executable_path/../Frameworks/libSDL2.dylib "${MACOS}/${MACOSX_BUNDLE_EXECUTABLE_NAME}"
    install_name_tool -change @rpath/libSDL2_image.dylib @executable_path/../Frameworks/libSDL2_image.dylib "${MACOS}/${MACOSX_BUNDLE_EXECUTABLE_NAME}"
    install_name_tool -change @rpath/libSDL2_ttf.dylib @executable_path/../Frameworks/libSDL2_ttf.dylib "${MACOS}/${MACOSX_BUNDLE_EXECUTABLE_NAME}"

    install_name_tool -change @rpath/libSDL2.dylib @executable_path/../Frameworks/libSDL2.dylib "${FRAMEWORKS}/libSDL2_image.dylib"
    install_name_tool -change @rpath/libSDL2.dylib @executable_path/../Frameworks/libSDL2.dylib "${FRAMEWORKS}/libSDL2_ttf.dylib"

    cat >"${CONTENTS}/Info.plist" <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleDevelopmentRegion</key>
    <string>English</string>
    <key>CFBundleExecutable</key>
    <string>${MACOSX_BUNDLE_EXECUTABLE_NAME}</string>
    <key>CFBundleGetInfoString</key>
    <string>${MACOSX_BUNDLE_INFO_STRING}</string>
    <key>CFBundleIconFile</key>
    <string>${MACOSX_BUNDLE_ICON_FILE}</string>
    <key>CFBundleIdentifier</key>
    <string>${MACOSX_BUNDLE_GUI_IDENTIFIER}</string>
    <key>CFBundleInfoDictionaryVersion</key>
    <string>6.0</string>
    <key>CFBundleLongVersionString</key>
    <string>${MACOSX_BUNDLE_LONG_VERSION_STRING}</string>
    <key>CFBundleName</key>
    <string>${MACOSX_BUNDLE_BUNDLE_NAME}</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleShortVersionString</key>
    <string>${MACOSX_BUNDLE_SHORT_VERSION_STRING}</string>
    <key>CFBundleSignature</key>
    <string>????</string>
    <key>CFBundleVersion</key>
    <string>${MACOSX_BUNDLE_BUNDLE_VERSION}</string>
    <key>NSHumanReadableCopyright</key>
    <string>${MACOSX_BUNDLE_COPYRIGHT}</string>
    <key>NSHighResolutionCapable</key>
    <true/>
</dict>
</plist>
EOF

    rm -rf build/dist

    mkdir -p build/dist

    cp -r "build/${MACOSX_BUNDLE_EXECUTABLE_NAME}.app" "build/dist/"

    ln -s /Applications "build/dist/Applications"

    hdiutil create -volname "${MACOSX_BUNDLE_EXECUTABLE_NAME}" -srcfolder "build/dist" -ov -format UDZO "build/${MACOSX_BUNDLE_EXECUTABLE_NAME}.dmg"

)
