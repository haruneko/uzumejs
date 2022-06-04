// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "EstimateF0.hpp"

#include <emscripten/bind.h>

using namespace emscripten;

class EstimateF0Wrapper : public wrapper<uzume::vocoder::EstimateF0> {
public:
    EMSCRIPTEN_WRAPPER(explicit EstimateF0Wrapper);
    bool operator()(uzume::vocoder::Contour *output, const uzume::vocoder::Waveform *input) final {
        return call<bool>("estimate", output, input);
    }
};

EMSCRIPTEN_BINDINGS(EstimateF0Bindings) {
    class_<uzume::vocoder::EstimateF0>("EstimateF0")
        .allow_subclass<EstimateF0Wrapper>("EstimateF0Wrapper")
        .function("estimate", &uzume::vocoder::EstimateF0::operator(), pure_virtual(), allow_raw_pointers());
}
