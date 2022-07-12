// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "data/ControlChange.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(ControlPointBindings) {
    value_array<uzume::vocoder::ControlPoint>("ControlPoint")
        .element(&uzume::vocoder::ControlPoint::position)
        .element(&uzume::vocoder::ControlPoint::ratio)
        ;
}

EMSCRIPTEN_BINDINGS(ControlChangeBindings) {
    class_<uzume::vocoder::ControlChange>("ControlChange")
        .smart_ptr<std::shared_ptr<uzume::vocoder::ControlChange>>("ControlChangeSharedPointer")
        .constructor(&std::make_shared<uzume::vocoder::ControlChange, double>)
        .function("at", &uzume::vocoder::ControlChange::at)
        .function("add", &uzume::vocoder::ControlChange::add)
        .function("clear", &uzume::vocoder::ControlChange::clear);
}
