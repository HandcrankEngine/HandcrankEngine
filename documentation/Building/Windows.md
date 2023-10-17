# Building on Windows

## Install CMake

```bash
winget install Kitware.CMake
```

## Install SDL Libraries

- [SDL](https://github.com/libsdl-org/SDL)
- [SDL_image](https://github.com/libsdl-org/SDL_image)
- [SDL_ttf](https://github.com/libsdl-org/SDL_ttf)

## Update CMakeLists.txt

```
if(WIN32)
    set(CMAKE_SYSTEM_NAME Windows)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
    set(SDL2_PATH C:/sdl/)
endif()
```

## Build

```bash
cmake .
make
```
