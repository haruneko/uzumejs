cmake_minimum_required(VERSION 3.1)

project(uzumewasm)

include(ExternalProject)

file(GLOB_RECURSE VOCODER_SOURCES ./lib/src/*.cpp)
file(GLOB_RECURSE VOCODER_HEADERS ./lib/src/*.hpp)

include_directories(uzumewasm PRIVATE ./lib/src/)

message(VOCODER_SOURCES)

add_executable(uzumewasm
        src/EstimateF0Bindings.cpp
        src/SpectrogramBindings.cpp
        src/SynthesizeWaveformBindings.cpp
        src/data/ContourBindings.cpp
        src/data/SpectrumBindings.cpp
        src/data/WaveformBindings.cpp
        src/spectrogram/WaveformSpectrogramBindings.cpp
        src/world/EstimateF0WithDIOBindings.cpp
        src/world/SynthesizeWaveformWithWORLDBindings.cpp
        ${VOCODER_SOURCES}
        ${VOCODER_HEADERS}
        )

if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    set(emcc_flags "--pre-js ${CMAKE_SOURCE_DIR}/src/resources/pre.js \
--post-js ${CMAKE_SOURCE_DIR}/src/resources/post.js \
--no-entry \
--bind \
-O1 \
-s STRICT=1 \
-s MALLOC=emmalloc \
-s WASM=1 \
-s ALLOW_MEMORY_GROWTH=1 \
-s FILESYSTEM=0 \
-s ENVIRONMENT=web,node \
")
    set_target_properties(uzumewasm PROPERTIES LINK_FLAGS ${emcc_flags})
endif()

