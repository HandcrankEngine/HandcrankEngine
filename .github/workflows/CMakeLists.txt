cmake_minimum_required(VERSION 3.14)

project(handcrank-engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")

set(SDL_LIBRARY_DIR "/tmp/.sdl/SDL-3.4.0/lib")
set(SDL_INCLUDE_DIR "/tmp/.sdl/SDL-3.4.0/include")

set(SDL_IMAGE_LIBRARY_DIR "/tmp/.sdl/SDL_image-3.2.6/lib")
set(SDL_IMAGE_INCLUDE_DIR "/tmp/.sdl/SDL_image-3.2.6/include")

set(SDL_TTF_LIBRARY_DIR "/tmp/.sdl/SDL_ttf-3.2.2/lib")
set(SDL_TTF_INCLUDE_DIR "/tmp/.sdl/SDL_ttf-3.2.2/include")

set(SDL_MIXER_LIBRARY_DIR "/tmp/.sdl/SDL_mixer-2.8.1/lib")
set(SDL_MIXER_INCLUDE_DIR "/tmp/.sdl/SDL_mixer-2.8.1/include/SDL2")

find_library(SDL3_LIBRARY NAMES SDL3 HINTS ${SDL_LIBRARY_DIR})
find_library(SDL3_IMAGE_LIBRARY NAMES SDL3_image HINTS ${SDL_IMAGE_LIBRARY_DIR})
find_library(SDL3_TTF_LIBRARY NAMES SDL3_ttf HINTS ${SDL_TTF_LIBRARY_DIR})
find_library(SDL2_MIXER_LIBRARY NAMES SDL2_mixer HINTS ${SDL_MIXER_LIBRARY_DIR})

include_directories(
    ${SDL_INCLUDE_DIR}
    ${SDL_IMAGE_INCLUDE_DIR}
    ${SDL_TTF_INCLUDE_DIR}
    ${SDL_MIXER_INCLUDE_DIR}
)

include_directories("../../fonts")
include_directories("../../images")
include_directories("../../include")
include_directories("../../examples")

file(GLOB_RECURSE SOURCES "../../src/*.cpp")
file(GLOB_RECURSE INCLUDES "../../include/*.hpp")
file(GLOB_RECURSE EXAMPLES "../../examples/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES} ${EXAMPLES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${SDL3_LIBRARY}
    ${SDL3_IMAGE_LIBRARY}
    ${SDL3_TTF_LIBRARY}
    ${SDL2_MIXER_LIBRARY}
)
