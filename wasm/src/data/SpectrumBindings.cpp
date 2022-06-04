// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "data/Spectrum.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(SpectrumBindings) {
    class_<uzume::vocoder::Spectrum>("Spectrum")
        .smart_ptr<std::shared_ptr<uzume::vocoder::Spectrum>>("shared_ptr<uzume::vocoder::Spectrum>")
        .constructor(&std::make_shared<uzume::vocoder::Spectrum, unsigned int>)
        .property("fftSize", &uzume::vocoder::Spectrum::fftSize)
        ;
}