// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "spectrogram/NaiveSpectrogram.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(NaiveSpectrogramBindings) {
    class_<uzume::vocoder::NaiveSpectrogram, base<uzume::vocoder::Spectrogram>>("NaiveSpectrogram")
        .smart_ptr<std::shared_ptr<uzume::vocoder::NaiveSpectrogram>>("shared_ptr<uzume::vocoder::NaiveSpectrogram>")
        .function("pickUpSpectrumAt", &uzume::vocoder::NaiveSpectrogram::pickUpSpectrumAt, allow_raw_pointers())
        .function("f0At", &uzume::vocoder::NaiveSpectrogram::f0At)
        .function("msLength", &uzume::vocoder::NaiveSpectrogram::msLength)
        .function("fftSize", &uzume::vocoder::NaiveSpectrogram::fftSize)
        .class_function("from", &uzume::vocoder::NaiveSpectrogram::from, allow_raw_pointers())
        ;
}
