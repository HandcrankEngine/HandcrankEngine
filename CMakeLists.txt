cmake_minimum_required(VERSION 3.14)

project(handcrank-engine LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")

include(FetchContent)

set(SDL2_VERSION "2.32.4")
set(SDL2_IMAGE_VERSION "2.8.8")
set(SDL2_TTF_VERSION "2.24.0")

if(EXISTS "/opt/homebrew/Cellar/sdl2/${SDL2_VERSION}/")
    set(SDL_LIBRARY_DIR "/opt/homebrew/Cellar/sdl2/${SDL2_VERSION}/lib")
    set(SDL_INCLUDE_DIR "/opt/homebrew/Cellar/sdl2/${SDL2_VERSION}/include/SDL2")
    find_library(SDL2_LIBRARY NAMES SDL2 HINTS ${SDL_LIBRARY_DIR})
    include_directories(${SDL_INCLUDE_DIR})
else()
    FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-${SDL2_VERSION}
    )
    set(SDL2_DISABLE_INSTALL ON)
    FetchContent_MakeAvailable(SDL2)
endif()

if(EXISTS "/opt/homebrew/Cellar/sdl2_image/${SDL2_IMAGE_VERSION}/")
    set(SDL_IMAGE_LIBRARY_DIR "/opt/homebrew/Cellar/sdl2_image/${SDL2_IMAGE_VERSION}/lib")
    set(SDL_IMAGE_INCLUDE_DIR "/opt/homebrew/Cellar/sdl2_image/${SDL2_IMAGE_VERSION}/include/SDL2")
    find_library(SDL2_IMAGE_LIBRARY NAMES SDL2_image HINTS ${SDL_IMAGE_LIBRARY_DIR})
    include_directories(${SDL_IMAGE_INCLUDE_DIR})
else()
    FetchContent_Declare(
        SDL2_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG release-${SDL2_IMAGE_VERSION}
    )
    set(SDL2IMAGE_INSTALL OFF)
    FetchContent_MakeAvailable(SDL2_image)
endif()

if(EXISTS "/opt/homebrew/Cellar/sdl2_ttf/${SDL2_TTF_VERSION}/")
    set(SDL_TTF_LIBRARY_DIR "/opt/homebrew/Cellar/sdl2_ttf/${SDL2_TTF_VERSION}/lib")
    set(SDL_TTF_INCLUDE_DIR "/opt/homebrew/Cellar/sdl2_ttf/${SDL2_TTF_VERSION}/include/SDL2")
    find_library(SDL2_TTF_LIBRARY NAMES SDL2_ttf HINTS ${SDL_TTF_LIBRARY_DIR})
    include_directories(${SDL_TTF_INCLUDE_DIR})
else()
    FetchContent_Declare(
        SDL2_ttf
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
        GIT_TAG release-${SDL2_TTF_VERSION}
    )
    set(SDL2TTF_INSTALL OFF)
    FetchContent_MakeAvailable(SDL2_ttf)
endif()

include_directories("fonts")
include_directories("images")
include_directories("include")
include_directories("examples")

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE INCLUDES "include/*.hpp")
file(GLOB_RECURSE EXAMPLES "examples/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES} ${EXAMPLES})

if(SDL2_LIBRARY)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY})
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
endif()

if(SDL2_IMAGE_LIBRARY)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_IMAGE_LIBRARY})
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_image::SDL2_image)
endif()

if(SDL2_TTF_LIBRARY)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_TTF_LIBRARY})
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_ttf::SDL2_ttf)
endif()

if(APPLE AND CMAKE_BUILD_TYPE MATCHES "[Rr]elease")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE TRUE
        BUNDLE TRUE
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.handcrankengine.demo"
        MACOSX_BUNDLE_BUNDLE_NAME "${PROJECT_NAME}"
        MACOSX_BUNDLE_BUNDLE_VERSION "1.0"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0"
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/resources/Info.plist.in"
    )

    set(MACOSX_BUNDLE_ICON_FILE icon.icns)
    set(APP_ICON_MACOSX ${CMAKE_SOURCE_DIR}/resources/icon.icns)
    set_source_files_properties(${APP_ICON_MACOSX} PROPERTIES
        MACOSX_PACKAGE_LOCATION "Resources"
    )

    target_sources(${PROJECT_NAME} PRIVATE ${APP_ICON_MACOSX})
endif()
