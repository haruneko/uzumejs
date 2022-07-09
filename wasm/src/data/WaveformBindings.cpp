// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "data/Waveform.hpp"
#include <emscripten/bind.h>

using namespace emscripten;


EMSCRIPTEN_BINDINGS(WaveformBindings) {
    class_<uzume::vocoder::Waveform>("Waveform")
            .smart_ptr<std::shared_ptr<uzume::vocoder::Waveform>>("shared_ptr<<uzume::vocoder::Waveform>")
            .constructor(&std::make_shared<uzume::vocoder::Waveform, unsigned int, unsigned int>)
            .function("msLength", &uzume::vocoder::Waveform::msLength)
            .function("clear", &uzume::vocoder::Waveform::clear)
            .function("indexAt", &uzume::vocoder::Waveform::indexAt)
            .function("rootMeanSquareBetween", select_overload<double(double, double)const>(&uzume::vocoder::Waveform::rootMeanSquareBetween))
            .function("maxAbsoluteValueBetween", select_overload<double(double, double)const>(&uzume::vocoder::Waveform::maxAbsoluteValueBetween))
            .function("at", &uzume::vocoder::Waveform::at)
            .function("setAt", &uzume::vocoder::Waveform::setAt)
            .property("length", &uzume::vocoder::Waveform::length)
            .property("samplingFrequency", &uzume::vocoder::Waveform::samplingFrequency)
            ;
}
