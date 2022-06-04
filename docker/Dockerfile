FROM ubuntu:20.04

# set noninteractive. See: https://qiita.com/yagince/items/deba267f789604643bab
ENV DEBIAN_FRONTEND=noninteractive

SHELL ["/bin/bash", "-l", "-c"] 

# install compiler and emsdk
RUN apt-get update
RUN apt-get install -y build-essential gdb cmake git python3
RUN git clone https://github.com/emscripten-core/emsdk.git \
 && cd emsdk \
 && ./emsdk install latest \
 && ./emsdk activate latest
RUN apt-get install -y nodejs npm && npm install -g tsembind
