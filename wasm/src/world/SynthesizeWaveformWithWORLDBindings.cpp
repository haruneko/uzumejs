// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "world/SynthesizeWaveformWithWORLD.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(SynthesizeWaveformWithWORLDBindings) {
    class_<uzume::vocoder::world::SynthesizeWaveformWithWORLD, base<uzume::vocoder::SynthesizeWaveform> >("SynthesizeWaveformWithWORLD")
            .smart_ptr<std::shared_ptr<uzume::vocoder::world::SynthesizeWaveformWithWORLD>>("shared_ptr<uzume::vocoder::world::SynthesizeWaveformWithWORLD>")
            .constructor(&std::make_shared<uzume::vocoder::world::SynthesizeWaveformWithWORLD>)
            .function("synthesize", &uzume::vocoder::world::SynthesizeWaveformWithWORLD::operator(), allow_raw_pointers());
}