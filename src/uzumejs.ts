import * as Wasm from "../resources/uzumewasm";

export interface UzumeJs extends Wasm.CustomEmbindModule {
    CreateWaveformFrom: (data: Float32Array, sampleRate: number) => Wasm.Waveform | null;
    ArrayFromWaveform:(waveform: Wasm.Waveform) => Float32Array;
}

export const CreateUzumeJs = (wasm: Wasm.CustomEmbindModule) => new UzumeJsImpl(wasm);

class UzumeJsImpl implements UzumeJs {
    constructor(private wasm: Wasm.CustomEmbindModule) { }
    ArraySpectrogramAggregator = this.wasm.ArraySpectrogramAggregator;
    Contour = this.wasm.Contour;
    EstimateF0 = this.wasm.EstimateF0;
    EstimateF0WithDIO = this.wasm.EstimateF0WithDIO;
    EstimateF0Wrapper = this.wasm.EstimateF0Wrapper;
    LinearTimeAxisMap = this.wasm.LinearTimeAxisMap;
    Spectrogram = this.wasm.Spectrogram;
    SpectrogramVector = this.wasm.SpectrogramVector;
    SpectrogramWrapper = this.wasm.SpectrogramWrapper;
    Spectrum = this.wasm.Spectrum;
    StretchedPartialSpectrogram = this.wasm.StretchedPartialSpectrogram;
    SynthesizeWaveform = this.wasm.SynthesizeWaveform;
    SynthesizeWaveformWrapper = this.wasm.SynthesizeWaveformWrapper;
    SynthesizeWaveformWithWORLD = this.wasm.SynthesizeWaveformWithWORLD;
    TimeAxisMap = this.wasm.TimeAxisMap;
    TimeAxisMapWrapper = this.wasm.TimeAxisMapWrapper;
    Waveform = this.wasm.Waveform;
    WaveformSpectrogram = this.wasm.WaveformSpectrogram;

    CreateWaveformFrom = (data: Float32Array, sampleRate: number) => {
        if(data.length == 0 || sampleRate <= 0) {
            return null;
        }
        const ret = new this.Waveform(data.length, sampleRate);
        for(let i = 0; i < data.length; i++) {
            ret.setAt(i, data[i]);
        }
        return ret;
    }

    ArrayFromWaveform = (waveform: Wasm.Waveform) => {
        if(waveform.length == 0) {
            return new Float32Array(0);
        }
        const ret = new Float32Array(waveform.length);
        for(let i = 0; i < waveform.length; i++) {
            ret[i] = waveform.at(i);
        }
        return ret;
    }
}
