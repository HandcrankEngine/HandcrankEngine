# Building on macOS

## Install CMake

```bash
brew install cmake
```

## Install SDL

```bash
brew install SDL3
brew install SDL3_image
brew install SDL3_ttf
brew install SDL2_mixer
```

## Build

### CMake (Recommended)

#### Debug Build

```bash
mkdir build/
cd build/
cmake ..
cmake --build .
```

#### Release Build

> Note: To generate DMG files on macOS, first build with cmake, then run `cpack`.

```bash
mkdir build/
cd build/
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

### g++

```bash
./bin/build-macos.sh
```

## Distribution

If you send the app to anyone before you [sign it](https://developer.apple.com/developer-id/), they will need to allow it via macOS Gatekeeper:

```bash
xattr -d com.apple.quarantine /Applications/handcrank-engine.app
```
