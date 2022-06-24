// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "TimeAxisMap.hpp"

#include <emscripten/bind.h>

using namespace emscripten;

class TimeAxisMapWrapper : public wrapper<uzume::vocoder::TimeAxisMap> {
public:
    EMSCRIPTEN_WRAPPER(explicit TimeAxisMapWrapper);
    double at(double ms) const final {
        return call<double>("at", ms);
    }
    double msLength() const final {
        return call<double>("msLength");
    }
};

EMSCRIPTEN_BINDINGS(TimeAxisMap) {
    class_<uzume::vocoder::TimeAxisMap>("TimeAxisMap")
        .allow_subclass<EstimateF0Wrapper>("TimeAxisMapWrapper")
        .function("at", &uzume::vocoder::TimeAxisMap::at, pure_virtual());
        .function("msLength", &uzume::vocoder::TimeAxisMap::msLength, pure_virtual());
}
