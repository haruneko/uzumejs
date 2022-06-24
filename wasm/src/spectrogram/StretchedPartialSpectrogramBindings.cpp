// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "spectrogram/StretchedPartialSpectrogram.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(StretchedPartialSpectrogramBindings) {
    class_<uzume::vocoder::StretchedPartialSpectrogram, base<uzume::vocoder::Spectrogram>>("StretchedPartialSpectrogram")
        .smart_ptr<std::shared_ptr<uzume::vocoder::StretchedPartialSpectrogram>>("shared_ptr<uzume::vocoder::StretchedPartialSpectrogram>")
        .constructor(&std::make_shared<uzume::vocoder::StretchedPartialSpectrogram, uzume::vocoder::Spectrogram*, uzume::vocoder::TimeAxisMap*>)
        .function("pickUpSpectrumAt", &uzume::vocoder::StretchedPartialSpectrogram::pickUpSpectrumAt, allow_raw_pointers())
        .function("f0At", &uzume::vocoder::StretchedPartialSpectrogram::f0At)
        .function("msLength", &uzume::vocoder::StretchedPartialSpectrogram::msLength)
        .function("fftSize", &uzume::vocoder::StretchedPartialSpectrogram::fftSize)
        ;
}
