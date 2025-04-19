cmake_minimum_required(VERSION 3.14)

project(handcrank-engine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")

include(FetchContent)

set(SDL3_VERSION "3.2.10")
set(SDL3_IMAGE_VERSION "3.2.4")
set(SDL3_TTF_VERSION "3.2.2")

if(EXISTS "/opt/homebrew/Cellar/sdl3/${SDL3_VERSION}/")
    set(SDL_LIBRARY_DIR "/opt/homebrew/Cellar/sdl3/${SDL3_VERSION}/lib")
    set(SDL_INCLUDE_DIR "/opt/homebrew/Cellar/sdl3/${SDL3_VERSION}/include")
    find_library(SDL3_LIBRARY NAMES SDL3 HINTS ${SDL_LIBRARY_DIR})
    include_directories(${SDL_INCLUDE_DIR})
else()
    FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-${SDL3_VERSION}
    )
    set(SDL3_DISABLE_INSTALL ON)
    FetchContent_MakeAvailable(SDL3)
endif()

if(EXISTS "/opt/homebrew/Cellar/sdl3_image/${SDL3_IMAGE_VERSION}/")
    set(SDL_IMAGE_LIBRARY_DIR "/opt/homebrew/Cellar/sdl3_image/${SDL3_IMAGE_VERSION}/lib")
    set(SDL_IMAGE_INCLUDE_DIR "/opt/homebrew/Cellar/sdl3_image/${SDL3_IMAGE_VERSION}/include")
    find_library(SDL3_IMAGE_LIBRARY NAMES SDL3_image HINTS ${SDL_IMAGE_LIBRARY_DIR})
    include_directories(${SDL_IMAGE_INCLUDE_DIR})
else()
    FetchContent_Declare(
        SDL3_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG release-${SDL3_IMAGE_VERSION}
    )
    set(SDL3IMAGE_INSTALL OFF)
    FetchContent_MakeAvailable(SDL3_image)
endif()

if(EXISTS "/opt/homebrew/Cellar/sdl3_ttf/${SDL3_TTF_VERSION}/")
    set(SDL_TTF_LIBRARY_DIR "/opt/homebrew/Cellar/sdl3_ttf/${SDL3_TTF_VERSION}/lib")
    set(SDL_TTF_INCLUDE_DIR "/opt/homebrew/Cellar/sdl3_ttf/${SDL3_TTF_VERSION}/include")
    find_library(SDL3_TTF_LIBRARY NAMES SDL3_ttf HINTS ${SDL_TTF_LIBRARY_DIR})
    include_directories(${SDL_TTF_INCLUDE_DIR})
else()
    FetchContent_Declare(
        SDL3_ttf
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
        GIT_TAG release-${SDL3_TTF_VERSION}
    )
    set(SDL3TTF_INSTALL OFF)
    FetchContent_MakeAvailable(SDL3_ttf)
endif()

include_directories("fonts")
include_directories("images")
include_directories("include")
include_directories("examples")

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE INCLUDES "include/*.hpp")
file(GLOB_RECURSE EXAMPLES "examples/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES} ${EXAMPLES})

if(SDL3_LIBRARY)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL3_LIBRARY})
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
endif()

if(SDL3_IMAGE_LIBRARY)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL3_IMAGE_LIBRARY})
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL3_image::SDL3_image)
endif()

if(SDL3_TTF_LIBRARY)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL3_TTF_LIBRARY})
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL3_ttf::SDL3_ttf)
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

    install(TARGETS ${PROJECT_NAME}
        BUNDLE DESTINATION .
        COMPONENT Runtime
    )

    set(CPACK_GENERATOR "DragNDrop")
    set(CPACK_DMG_VOLUME_NAME "${PROJECT_NAME}")
    set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${CMAKE_PROJECT_VERSION}")
    set(CPACK_DMG_FORMAT "UDZO")
    set(CPACK_SYSTEM_NAME "Darwin")
    set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_BINARY_DIR}/build")

    set(CPACK_BINARY_STGZ OFF)
    set(CPACK_BINARY_TGZ OFF)
    set(CPACK_BINARY_TZ OFF)

    include(CPack)
endif()
