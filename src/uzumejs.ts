import { CustomEmbindModule, Waveform } from "../resources/uzumewasm";

export interface UzumeJs extends CustomEmbindModule {
    CreateWaveformFrom: (data: Float32Array, sampleRate: number) => Waveform | null;
    ArrayFromWaveform:(waveform: Waveform) => Float32Array;
}

export class UzumeJsImpl implements UzumeJs {
    constructor(private wasm: CustomEmbindModule) { }
    EstimateF0 = this.wasm.EstimateF0;
    EstimateF0Wrapper = this.wasm.EstimateF0Wrapper;
    Contour = this.wasm.Contour;
    Waveform = this.wasm.Waveform;
    Spectrogram = this.wasm.Spectrogram;
    SpectrogramWrapper = this.wasm.SpectrogramWrapper;
    Spectrum = this.wasm.Spectrum;
    SynthesizeWaveform = this.wasm.SynthesizeWaveform;
    SynthesizeWaveformWrapper = this.wasm.SynthesizeWaveformWrapper;
    SynthesizeWaveformWithWORLD = this.wasm.SynthesizeWaveformWithWORLD;
    WaveformSpectrogram = this.wasm.WaveformSpectrogram;
    EstimateF0WithDIO = this.wasm.EstimateF0WithDIO;
    StretchedPartialSpectrogram = this.wasm.StretchedPartialSpectrogram;
    LinearTimeAxisMap = this.wasm.LinearTimeAxisMap;
    ArraySpectrogramAggregator = this.wasm.ArraySpectrogramAggregator;
    SpectrogramVector = this.wasm.SpectrogramVector;

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

    ArrayFromWaveform = (waveform: Waveform) => {
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
