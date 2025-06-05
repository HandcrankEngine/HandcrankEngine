FROM ubuntu:latest

ARG SDL_VERSION=2.32.8
ARG SDL_IMAGE_VERSION=2.8.8
ARG SDL_TTF_VERSION=2.24.0
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

# Install SDL
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL/releases/download/release-${SDL_VERSION}/SDL2-${SDL_VERSION}.tar.gz > SDL.tar.gz && \
    mkdir SDL-${SDL_VERSION} &&  \
    tar -xzvf SDL.tar.gz --strip-components=1 -C SDL-${SDL_VERSION} && \
    cd SDL-${SDL_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL-${SDL_VERSION} && \
    make && \
    make install

ENV PKG_CONFIG_PATH=/tmp/.sdl/SDL-${SDL_VERSION}/lib/pkgconfig:${PKG_CONFIG_PATH}

# Install SDL_image
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL_image/releases/download/release-${SDL_IMAGE_VERSION}/SDL2_image-${SDL_IMAGE_VERSION}.tar.gz > SDL_image.tar.gz && \
    mkdir SDL_image-${SDL_IMAGE_VERSION} &&  \
    tar -xzvf SDL_image.tar.gz --strip-components=1 -C SDL_image-${SDL_IMAGE_VERSION} && \
    cd SDL_image-${SDL_IMAGE_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL_image-${SDL_IMAGE_VERSION} && \
    make && \
    make install

# Install SDL_ttf
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL_ttf/releases/download/release-${SDL_TTF_VERSION}/SDL2_ttf-${SDL_TTF_VERSION}.tar.gz > SDL_ttf.tar.gz && \
    mkdir SDL_ttf-${SDL_TTF_VERSION} &&  \
    tar -xzvf SDL_ttf.tar.gz --strip-components=1 -C SDL_ttf-${SDL_TTF_VERSION} && \
    cd SDL_ttf-${SDL_TTF_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL_ttf-${SDL_TTF_VERSION} && \
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
