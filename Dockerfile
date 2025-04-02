FROM ubuntu:latest

ARG SDL3_VERSION=3.2.12
ARG SDL3_IMAGE_VERSION=3.2.4
ARG SDL3_TTF_VERSION=3.2.2

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

# Install SDL3
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -LO https://github.com/libsdl-org/SDL/releases/download/release-${SDL3_VERSION}/SDL3-${SDL3_VERSION}.tar.gz && \
    tar -xzvf SDL3-${SDL3_VERSION}.tar.gz && \
    cd SDL3-${SDL3_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL3-${SDL3_VERSION} && \
    make && \
    make install

ENV PKG_CONFIG_PATH=/tmp/.sdl/SDL3-${SDL3_VERSION}/lib/pkgconfig:${PKG_CONFIG_PATH}

# Install SDL3_image
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -LO https://github.com/libsdl-org/SDL_image/releases/download/release-${SDL3_IMAGE_VERSION}/SDL3_image-${SDL3_IMAGE_VERSION}.tar.gz && \
    tar -xzvf SDL3_image-${SDL3_IMAGE_VERSION}.tar.gz && \
    cd SDL3_image-${SDL3_IMAGE_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL3_image-${SDL3_IMAGE_VERSION} && \
    make && \
    make install

# Install SDL3_ttf
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -LO https://github.com/libsdl-org/SDL_ttf/releases/download/release-${SDL3_TTF_VERSION}/SDL3_ttf-${SDL3_TTF_VERSION}.tar.gz && \
    tar -xzvf SDL3_ttf-${SDL3_TTF_VERSION}.tar.gz && \
    cd SDL3_ttf-${SDL3_TTF_VERSION} && \
    ./configure --prefix=/tmp/.sdl/SDL3_ttf-${SDL3_TTF_VERSION} && \
    make && \
    make install

WORKDIR /app
