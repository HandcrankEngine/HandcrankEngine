cmake_minimum_required(VERSION 3.14)

project(handcrank-engine LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")

include(FetchContent)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.2.10
)

FetchContent_Declare(
    SDL3_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-3.2.4
)

FetchContent_Declare(
    SDL3_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG release-3.2.2
)

set(SDL3_DISABLE_INSTALL ON)
set(SDL3IMAGE_INSTALL OFF)
set(SDL3TTF_INSTALL OFF)

FetchContent_MakeAvailable(SDL3 SDL3_image SDL3_ttf)

include_directories("fonts")
include_directories("images")
include_directories("include")
include_directories("examples")

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE INCLUDES "include/*.hpp")
file(GLOB_RECURSE EXAMPLES "examples/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES} ${EXAMPLES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${SDL3_SOURCE_DIR}/include
    ${SDL3_image_SOURCE_DIR}/include
    ${SDL3_ttf_SOURCE_DIR}/include
)
