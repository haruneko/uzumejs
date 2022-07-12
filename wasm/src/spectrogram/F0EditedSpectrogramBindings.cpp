// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "spectrogram/F0EditedSpectrogram.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(F0EditedSpectrogramBindings) {
    class_<uzume::vocoder::F0EditedSpectrogram, base<uzume::vocoder::Spectrogram>>("F0EditedSpectrogram")
        .smart_ptr<std::shared_ptr<uzume::vocoder::F0EditedSpectrogram>>("shared_ptr<uzume::vocoder::F0EditedSpectrogram>")
        .constructor(&std::make_shared<uzume::vocoder::F0EditedSpectrogram, const uzume::vocoder::Spectrogram *, const uzume::vocoder::ControlChange &>, allow_raw_pointers())
        .function("pickUpSpectrumAt", &uzume::vocoder::F0EditedSpectrogram::pickUpSpectrumAt, allow_raw_pointers())
        .function("f0At", &uzume::vocoder::F0EditedSpectrogram::f0At)
        .function("msLength", &uzume::vocoder::F0EditedSpectrogram::msLength)
        .function("fftSize", &uzume::vocoder::F0EditedSpectrogram::fftSize)
        ;
}
