#! /bin/bash

# Use nodejs in emsdk because nodejs installed by apt-get fails tsembind. 
source "/emsdk/emsdk_env.sh"

if [ ! -d build ]; then
  mkdir build
fi
cd build
# implicit dependency on Dockerfile. emsdk should be installed on `/emsdk`
cmake -DCMAKE_TOOLCHAIN_FILE=/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake ..
cmake --build . --target all -- -j 6
tsembind uzumewasm.js > uzumewasm.d.ts
cd ..
