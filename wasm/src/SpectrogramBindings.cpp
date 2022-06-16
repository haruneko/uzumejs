// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "Spectrogram.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

class SpectrogramWrapper : public wrapper<uzume::vocoder::Spectrogram> {
public:
    EMSCRIPTEN_WRAPPER(explicit SpectrogramWrapper);

    bool pickUpSpectrumAt(uzume::vocoder::Spectrum *destination, double ms) const final {
        return call<bool>("pickUpSpectrumAt", destination, ms);
    }

    double f0At(double ms) const final {
        return call<double>("f0At", ms);
    }

    double msLength() const final {
        return call<double>("msLength");
    }

    unsigned int fftSize() const final {
        return call<unsigned int>("fftSize");
    }
};

EMSCRIPTEN_BINDINGS(SpectrogramBindings) {
    class_<uzume::vocoder::Spectrogram>("Spectrogram")
        .allow_subclass<SpectrogramWrapper>("SpectrogramWrapper")
        .smart_ptr<std::shared_ptr<uzume::vocoder::Spectrogram>>("shared_ptr<<uzume::vocoder::Spectrogram>")
        .function("pickUpSpectrumAt", &uzume::vocoder::Spectrogram::pickUpSpectrumAt, pure_virtual(), allow_raw_pointers())
        .function("f0At", &uzume::vocoder::Spectrogram::f0At, pure_virtual())
        .function("msLength", &uzume::vocoder::Spectrogram::msLength, pure_virtual())
        .function("fftSize", &uzume::vocoder::Spectrogram::fftSize, pure_virtual());
}
