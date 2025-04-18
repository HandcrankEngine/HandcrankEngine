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

```bash
mkdir build/
cd build/
cmake ..
# cmake .. -DCMAKE_BUILD_TYPE=Debug
# cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```
