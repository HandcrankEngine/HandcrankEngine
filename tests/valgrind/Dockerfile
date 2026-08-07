FROM ubuntu:latest

ARG SDL_VERSION=3.4.14
ARG SDL_IMAGE_VERSION=3.4.4
ARG SDL_TTF_VERSION=3.2.2
ARG SDL_MIXER_VERSION=3.2.4

ENV DEPS_PREFIX=/usr/local

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    curl \
    gnome-desktop-testing \
    libasound2-dev \
    libaudio-dev \
    libdbus-1-dev \
    libdrm-dev \
    libegl1-mesa-dev \
    libfreetype-dev \
    libfreetype6-dev \
    libgbm-dev \
    libgl1-mesa-dev \
    libgles2-mesa-dev \
    libharfbuzz-dev \
    libibus-1.0-dev \
    libjack-dev \
    libjpeg-dev \
    libpng-dev \
    libpulse-dev \
    libsndio-dev \
    libtiff-dev \
    libudev-dev \
    libwebp-dev \
    libx11-dev \
    libxcursor-dev \
    libxext-dev \
    libxfixes-dev \
    libxi-dev \
    libxkbcommon-dev \
    libxrandr-dev \
    libxss-dev \
    libxtst-dev \
    make \
    ninja-build \
    pkg-config \
    valgrind && rm -rf /var/lib/apt/lists/*

# Install SDL
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL/releases/download/release-${SDL_VERSION}/SDL3-${SDL_VERSION}.tar.gz > SDL.tar.gz && \
    mkdir SDL-${SDL_VERSION} && \
    tar -xzvf SDL.tar.gz --strip-components=1 -C SDL-${SDL_VERSION} && \
    rm SDL.tar.gz && \
    cd SDL-${SDL_VERSION} && \
    cmake -S . -B dist \
        -DCMAKE_INSTALL_PREFIX="${DEPS_PREFIX}" \
        -DCMAKE_BUILD_TYPE=Release \
        -DSDL_SHARED=ON \
        -DSDL_STATIC=ON \
        -DSDL_TESTS=OFF \
        -DSDL_EXAMPLES=OFF \
        -GNinja && \
    cmake --build dist -j$(nproc) && \
    cmake --install dist

# Install SDL_image
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL_image/releases/download/release-${SDL_IMAGE_VERSION}/SDL3_image-${SDL_IMAGE_VERSION}.tar.gz > SDL_image.tar.gz && \
    mkdir SDL_image-${SDL_IMAGE_VERSION} && \
    tar -xzvf SDL_image.tar.gz --strip-components=1 -C SDL_image-${SDL_IMAGE_VERSION} && \
    rm SDL_image.tar.gz && \
    cd SDL_image-${SDL_IMAGE_VERSION} && \
    cmake -S . -B dist \
        -DCMAKE_INSTALL_PREFIX="${DEPS_PREFIX}" \
        -DSDL3_DIR="${DEPS_PREFIX}/lib/cmake/SDL3" \
        -DCMAKE_BUILD_TYPE=Release \
        -DSDL3IMAGE_SHARED=OFF \
        -DSDL3IMAGE_BUILD_SHARED_LIBS=OFF \
        -DSDLIMAGE_SAMPLES=OFF \
        -GNinja && \
    cmake --build dist -j$(nproc) && \
    cmake --install dist

# Install SDL_ttf
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL_ttf/releases/download/release-${SDL_TTF_VERSION}/SDL3_ttf-${SDL_TTF_VERSION}.tar.gz > SDL_ttf.tar.gz && \
    mkdir SDL_ttf-${SDL_TTF_VERSION} && \
    tar -xzvf SDL_ttf.tar.gz --strip-components=1 -C SDL_ttf-${SDL_TTF_VERSION} && \
    rm SDL_ttf.tar.gz && \
    cd SDL_ttf-${SDL_TTF_VERSION} && \
    cmake -S . -B dist \
        -DCMAKE_INSTALL_PREFIX="${DEPS_PREFIX}" \
        -DSDL3_DIR="${DEPS_PREFIX}/lib/cmake/SDL3" \
        -DCMAKE_BUILD_TYPE=Release \
        -DSDL3TTF_SHARED=OFF \
        -DSDLTTF_SAMPLES=OFF \
        -DSDL3TTF_HARFBUZZ=ON \
        -GNinja && \
    cmake --build dist -j$(nproc) && \
    cmake --install dist

# Install SDL_mixer
RUN mkdir -p /tmp/.sdl && \
    cd /tmp/.sdl && \
    curl -L https://github.com/libsdl-org/SDL_mixer/releases/download/release-${SDL_MIXER_VERSION}/SDL3_mixer-${SDL_MIXER_VERSION}.tar.gz > SDL_mixer.tar.gz && \
    mkdir SDL_mixer-${SDL_MIXER_VERSION} && \
    tar -xzvf SDL_mixer.tar.gz --strip-components=1 -C SDL_mixer-${SDL_MIXER_VERSION} && \
    rm SDL_mixer.tar.gz && \
    cd SDL_mixer-${SDL_MIXER_VERSION} && \
    cmake -S . -B dist \
        -DCMAKE_INSTALL_PREFIX="${DEPS_PREFIX}" \
        -DSDL3_DIR="${DEPS_PREFIX}/lib/cmake/SDL3" \
        -DCMAKE_BUILD_TYPE=Release \
        -DSDL3MIXER_SHARED=OFF \
        -DSDLMIXER_SAMPLES=OFF \
        -GNinja && \
    cmake --build dist -j$(nproc) && \
    cmake --install dist

RUN ldconfig

WORKDIR /app
