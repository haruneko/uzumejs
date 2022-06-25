// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "data/LinearTimeAxisMap.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(LinearTimeAxisMapBindings) {
    class_<uzume::vocoder::LinearTimeAxisMap, base<uzume::vocoder::TimeAxisMap>>("LinearTimeAxisMap")
        .smart_ptr<std::shared_ptr<uzume::vocoder::LinearTimeAxisMap>>("shared_ptr<uzume::vocoder::LinearTimeAxisMap>")
        .constructor(&std::make_shared<uzume::vocoder::LinearTimeAxisMap, double, double, double>)
        .function("at", &uzume::vocoder::LinearTimeAxisMap::at)
        .function("msLength", &uzume::vocoder::LinearTimeAxisMap::msLength)
        ;
}
