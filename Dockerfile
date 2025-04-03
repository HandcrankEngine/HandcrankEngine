FROM ubuntu:latest

ARG SDL2_VERSION=2.32.4
ARG SDL2_IMAGE_VERSION=2.8.8
ARG SDL2_TTF_VERSION=2.24.0

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y \
    curl \
    build-essential \
    pkg-config \
    libpng-dev \
    libjpeg-dev \
    libtiff-dev \
    libwebp-dev \
    libfreetype-dev

# Install SDL2
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -LO https://github.com/libsdl-org/SDL/releases/download/release-${SDL2_VERSION}/SDL2-${SDL2_VERSION}.tar.gz && \
    tar -xzvf SDL2-${SDL2_VERSION}.tar.gz && \
    cd SDL2-${SDL2_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL2-${SDL2_VERSION} && \
    make && \
    make install

ENV PKG_CONFIG_PATH=/tmp/.sdl/SDL2-${SDL2_VERSION}/lib/pkgconfig:${PKG_CONFIG_PATH}

# Install SDL2_image
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -LO https://github.com/libsdl-org/SDL_image/releases/download/release-${SDL2_IMAGE_VERSION}/SDL2_image-${SDL2_IMAGE_VERSION}.tar.gz && \
    tar -xzvf SDL2_image-${SDL2_IMAGE_VERSION}.tar.gz && \
    cd SDL2_image-${SDL2_IMAGE_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL2_image-${SDL2_IMAGE_VERSION} && \
    make && \
    make install

# Install SDL2_ttf
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -LO https://github.com/libsdl-org/SDL_ttf/releases/download/release-${SDL2_TTF_VERSION}/SDL2_ttf-${SDL2_TTF_VERSION}.tar.gz && \
    tar -xzvf SDL2_ttf-${SDL2_TTF_VERSION}.tar.gz && \
    cd SDL2_ttf-${SDL2_TTF_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL2_ttf-${SDL2_TTF_VERSION} && \
    make && \
    make install

WORKDIR /app
