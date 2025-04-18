# Building on Windows

## Install CMake

```bash
winget install Kitware.CMake
```

## Build

Build the release:

```bash
mkdir build/
cd build/
cmake ..
# cmake .. -DCMAKE_BUILD_TYPE=Debug
# cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```
