# Building on macOS

## Install CMake

```bash
brew install cmake
```

## Install SDL

```bash
brew install SDL2
brew install SDL2_image
brew install SDL2_ttf
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
