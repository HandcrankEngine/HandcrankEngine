# Building on Windows

## Install CMake

```bash
winget install Kitware.CMake
```

## Setup

For Windows, you will need to update the entry point of the app to use `WinMain` as shown below.

```cpp
#define SDL_MAIN_HANDLED

#include "Handcrank/Handcrank.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace Handcrank;

auto game = std::make_unique<Game>();

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nShowCmd)
#else
auto main() -> int
#endif
{
    game->SetTitle("Handcrank Engine");

    return game->Run();
}
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

```bash
mkdir build/
cd build/
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```
