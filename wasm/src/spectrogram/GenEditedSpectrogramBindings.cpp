// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "spectrogram/GenEditedSpectrogram.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(GenEditedSpectrogramBindings) {
    class_<uzume::vocoder::GenEditedSpectrogram, base<uzume::vocoder::Spectrogram>>("GenEditedSpectrogram")
        .smart_ptr<std::shared_ptr<uzume::vocoder::GenEditedSpectrogram>>("shared_ptr<uzume::vocoder::GenEditedSpectrogram>")
        .constructor(&std::make_shared<uzume::vocoder::GenEditedSpectrogram, const uzume::vocoder::Spectrogram *, const uzume::vocoder::ControlChange &>, allow_raw_pointers())
        .function("pickUpSpectrumAt", &uzume::vocoder::GenEditedSpectrogram::pickUpSpectrumAt, allow_raw_pointers())
        .function("f0At", &uzume::vocoder::GenEditedSpectrogram::f0At)
        .function("msLength", &uzume::vocoder::GenEditedSpectrogram::msLength)
        .function("fftSize", &uzume::vocoder::GenEditedSpectrogram::fftSize)
        ;
}
