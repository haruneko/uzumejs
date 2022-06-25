// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "spectrogram/ArraySpectrogramAggregator.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(ArraySpectrogramAggregatorBindings) {
    register_vector<const uzume::vocoder::Spectrogram *>("SpectrogramVector");
    class_<uzume::vocoder::ArraySpectrogramAggregator>("ArraySpectrogramAggregator")
        .smart_ptr<std::shared_ptr<uzume::vocoder::ArraySpectrogramAggregator>>("shared_ptr<uzume::vocoder::ArraySpectrogramAggregator>")
        .class_function("from", &uzume::vocoder::ArraySpectrogramAggregator::from, allow_raw_pointers())
        .function("pickUpSpectrumAt", &uzume::vocoder::ArraySpectrogramAggregator::pickUpSpectrumAt, allow_raw_pointers())
        .function("f0At", &uzume::vocoder::ArraySpectrogramAggregator::f0At)
        .function("msLength", &uzume::vocoder::ArraySpectrogramAggregator::msLength)
        .function("fftSize", &uzume::vocoder::ArraySpectrogramAggregator::fftSize)
        ;
}