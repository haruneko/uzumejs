// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "data/Waveform.hpp"
#include <emscripten/bind.h>

using namespace emscripten;

uzume::vocoder::Waveform *read(const std::string &path) {
    return uzume::vocoder::Waveform::read(path.data());
};

bool save(const std::string &path, const uzume::vocoder::Waveform *w) {
    return w->save(path.data());
}

EMSCRIPTEN_BINDINGS(WaveformBindings) {
    class_<uzume::vocoder::Waveform>("Waveform")
            .smart_ptr<std::shared_ptr<uzume::vocoder::Waveform>>("shared_ptr<<uzume::vocoder::Waveform>")
            .constructor(&std::make_shared<uzume::vocoder::Waveform, unsigned int, unsigned int>)
            .function("msLength", &uzume::vocoder::Waveform::msLength)
            .function("save", &uzume::vocoder::Waveform::save, allow_raw_pointers())
            .function("clear", &uzume::vocoder::Waveform::clear)
            .function("indexAt", &uzume::vocoder::Waveform::indexAt)
            .function("rootMeanSquareBetween", select_overload<double(double, double)const>(&uzume::vocoder::Waveform::rootMeanSquareBetween))
            .function("maxAbsoluteValueBetween", select_overload<double(double, double)const>(&uzume::vocoder::Waveform::maxAbsoluteValueBetween))
            .property("length", &uzume::vocoder::Waveform::length)
            .property("samplingFrequency", &uzume::vocoder::Waveform::samplingFrequency)
            .class_function("read", &read, allow_raw_pointers())
            .class_function("save", &save, allow_raw_pointers())
            ;
}
