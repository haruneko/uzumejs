// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "world/EstimateF0WithDIO.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(EstimateF0WithDIOBindings) {
    class_<uzume::vocoder::world::EstimateF0WithDIO, base<uzume::vocoder::EstimateF0>>("EstimateF0WithDIO")
        .smart_ptr<std::shared_ptr<uzume::vocoder::world::EstimateF0WithDIO>>("shared_ptr<uzume::vocoder::world::EstimateF0WithDIO>")
        .constructor(&std::make_shared<uzume::vocoder::world::EstimateF0WithDIO, double>)
        .function("estimate", &uzume::vocoder::world::EstimateF0WithDIO::operator(), allow_raw_pointers())
        .function("getF0LengthFor", &uzume::vocoder::world::EstimateF0WithDIO::getF0LengthFor);
}
