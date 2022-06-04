// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "spectrogram/WaveformSpectrogram.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(WaveformSpectrogramBindings) {
    class_<uzume::vocoder::WaveformSpectrogram, base<uzume::vocoder::Spectrogram>>("WaveformSpectrogram")
        .smart_ptr<std::shared_ptr<uzume::vocoder::WaveformSpectrogram>>("shared_ptr<uzume::vocoder::WaveformSpectrogram>")
        .constructor(&std::make_shared<uzume::vocoder::WaveformSpectrogram, uzume::vocoder::Waveform*>)
        .function("pickUpSpectrumAt", &uzume::vocoder::WaveformSpectrogram::pickUpSpectrumAt, allow_raw_pointers())
        .function("f0At", &uzume::vocoder::WaveformSpectrogram::f0At)
        .function("msLength", &uzume::vocoder::WaveformSpectrogram::msLength)
        .function("fftSize", &uzume::vocoder::WaveformSpectrogram::fftSize)
        ;
}
