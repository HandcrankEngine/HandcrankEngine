FROM ubuntu:latest

ARG SDL_VERSION=3.4.0
ARG SDL_IMAGE_VERSION=3.2.6
ARG SDL_TTF_VERSION=3.2.2
ARG SDL_MIXER_VERSION=2.8.1

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y \
    curl \
    build-essential \
    pkg-config \
    libpng-dev \
    libjpeg-dev \
    libtiff-dev \
    libwebp-dev \
    libfreetype-dev \
    valgrind

RUN apt-get install -y \
    cmake \
    make \
    ninja-build \
    gnome-desktop-testing \
    libasound2-dev \
    libpulse-dev \
    libaudio-dev \
    libjack-dev \
    libsndio-dev \
    libx11-dev \
    libxext-dev \
    libxrandr-dev \
    libxcursor-dev \
    libxfixes-dev \
    libxi-dev \
    libxss-dev \
    libxtst-dev \
    libxkbcommon-dev \
    libdrm-dev \
    libgbm-dev \
    libgl1-mesa-dev \
    libgles2-mesa-dev \
    libegl1-mesa-dev \
    libdbus-1-dev \
    libibus-1.0-dev \
    libudev-dev

RUN apt-get install -y \
    libfreetype6-dev \
    libharfbuzz-dev

# Install SDL
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL/releases/download/release-${SDL_VERSION}/SDL3-${SDL_VERSION}.tar.gz > SDL.tar.gz && \
    mkdir SDL-${SDL_VERSION} &&  \
    tar -xzvf SDL.tar.gz --strip-components=1 -C SDL-${SDL_VERSION} && \
    cd SDL-${SDL_VERSION} && \
    mkdir build && \
    cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=/tmp/.sdl/SDL-${SDL_VERSION} -DCMAKE_BUILD_TYPE=Release -DSDL_SHARED=ON -DSDL_STATIC=ON && \
    make && \
    make install

ENV PKG_CONFIG_PATH=/tmp/.sdl/SDL-${SDL_VERSION}/lib/pkgconfig:${PKG_CONFIG_PATH}
ENV CMAKE_PREFIX_PATH=/tmp/.sdl/SDL-${SDL_VERSION}:${CMAKE_PREFIX_PATH}

# Install SDL_image
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL_image/releases/download/release-${SDL_IMAGE_VERSION}/SDL3_image-${SDL_IMAGE_VERSION}.tar.gz > SDL_image.tar.gz && \
    mkdir SDL_image-${SDL_IMAGE_VERSION} &&  \
    tar -xzvf SDL_image.tar.gz --strip-components=1 -C SDL_image-${SDL_IMAGE_VERSION} && \
    cd SDL_image-${SDL_IMAGE_VERSION} && \
    mkdir build && \
    cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=/tmp/.sdl/SDL_image-${SDL_IMAGE_VERSION} -DCMAKE_BUILD_TYPE=Release -DSDL_SHARED=ON -DSDL_STATIC=ON && \
    make && \
    make install

# Install SDL_ttf
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL_ttf/releases/download/release-${SDL_TTF_VERSION}/SDL3_ttf-${SDL_TTF_VERSION}.tar.gz > SDL_ttf.tar.gz && \
    mkdir SDL_ttf-${SDL_TTF_VERSION} &&  \
    tar -xzvf SDL_ttf.tar.gz --strip-components=1 -C SDL_ttf-${SDL_TTF_VERSION} && \
    cd SDL_ttf-${SDL_TTF_VERSION} && \
    mkdir build && \
    cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=/tmp/.sdl/SDL_ttf-${SDL_TTF_VERSION} -DCMAKE_BUILD_TYPE=Release -DSDL_SHARED=ON -DSDL_STATIC=ON && \
    make && \
    make install

# Install SDL_mixer
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL_mixer/releases/download/release-${SDL_MIXER_VERSION}/SDL2_mixer-${SDL_MIXER_VERSION}.tar.gz > SDL_mixer.tar.gz && \
    mkdir SDL_mixer-${SDL_MIXER_VERSION} &&  \
    tar -xzvf SDL_mixer.tar.gz --strip-components=1 -C SDL_mixer-${SDL_MIXER_VERSION} && \
    cd SDL_mixer-${SDL_MIXER_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL_mixer-${SDL_MIXER_VERSION} && \
    make && \
    make install

WORKDIR /app
