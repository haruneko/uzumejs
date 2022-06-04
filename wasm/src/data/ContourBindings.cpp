// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "data/Contour.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(ContourBindings) {
    class_<uzume::vocoder::Contour>("Contour")
        .smart_ptr<std::shared_ptr<uzume::vocoder::Contour>>("shared_ptr<uzume::vocoder::Contour>")
        .constructor(&std::make_shared<uzume::vocoder::Contour, double, double>)
        .function("at", &uzume::vocoder::Contour::at)
        .function("msLength", &uzume::vocoder::Contour::msLength)
        .property("length", &uzume::vocoder::Contour::length);
}
