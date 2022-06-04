// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "SynthesizeWaveform.hpp"

#include <emscripten/bind.h>

using namespace emscripten;

class SynthesizeWaveformWrapper : public wrapper<uzume::vocoder::SynthesizeWaveform> {
public:
    EMSCRIPTEN_WRAPPER(explicit SynthesizeWaveformWrapper);
    bool operator()(uzume::vocoder::Waveform *output, const uzume::vocoder::Spectrogram *input) final {
        return call<bool>("synthesize", output, input);
    }
};

EMSCRIPTEN_BINDINGS(SynthesizeWaveformBindings) {
    class_<uzume::vocoder::SynthesizeWaveform>("SynthesizeWaveform")
        .allow_subclass<SynthesizeWaveformWrapper>("SynthesizeWaveformWrapper")
        .function("synthesize", &uzume::vocoder::SynthesizeWaveform::operator(), pure_virtual(), allow_raw_pointers());
}
