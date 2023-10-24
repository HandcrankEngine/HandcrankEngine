FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y curl
RUN apt-get install -y pkg-config
RUN apt-get install -y build-essential

RUN mkdir -p /tmp/.sdl

## Install SDL2

WORKDIR /tmp/.sdl

RUN curl -LO https://github.com/libsdl-org/SDL/releases/download/release-2.28.5/SDL2-2.28.5.tar.gz
RUN tar -xzvf SDL2-2.28.5.tar.gz

WORKDIR /tmp/.sdl/SDL2-2.28.5

RUN ./configure --prefix=/tmp/.sdl/SDL2-2.28.5
RUN make
RUN make install

ENV PKG_CONFIG_PATH=/tmp/.sdl/SDL2-2.28.5/lib/pkgconfig:$PKG_CONFIG_PATH

## Install SDL2_image

WORKDIR /tmp/.sdl

RUN curl -LO https://github.com/libsdl-org/SDL_image/releases/download/release-2.6.3/SDL2_image-2.6.3.tar.gz
RUN tar -xzvf SDL2_image-2.6.3.tar.gz

WORKDIR /tmp/.sdl/SDL2_image-2.6.3

RUN ./configure --prefix=/tmp/.sdl/SDL2_image-2.6.3
RUN make
RUN make install

## Install SDL2_ttf

WORKDIR /tmp/.sdl

RUN curl -LO https://github.com/libsdl-org/SDL_ttf/releases/download/release-2.20.2/SDL2_ttf-2.20.2.tar.gz
RUN tar -xzvf SDL2_ttf-2.20.2.tar.gz

WORKDIR /tmp/.sdl/SDL2_ttf-2.20.2

RUN ./configure --prefix=/tmp/.sdl/SDL2_ttf-2.20.2
RUN make
RUN make install

RUN apt-get update
RUN apt-get install -y cmake

COPY . /usr/src/app

WORKDIR /usr/src/app

RUN cmake .github/workflows/
RUN make
