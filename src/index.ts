import * as Wasm from "../resources/uzumewasm";
import { UzumeJs, UzumeJsImpl } from "./uzumejs";

const uzumejs: (...args: any[]) => Promise<UzumeJs> = (args) => {
    const js = require("../resources/uzumewasm.js");
    console.log(js);
    const ret: Promise<UzumeJs> = js(args).then((v: Wasm.CustomEmbindModule) => new UzumeJsImpl(v));
    return ret;
}

export default uzumejs;

export type ArraySpectrogramAggregator = Wasm.ArraySpectrogramAggregator;
export type Contour = Wasm.Contour;
export type EstimateF0 = Wasm.EstimateF0;
export type EstimateF0WithDIO = Wasm.EstimateF0WithDIO;
export type LinearTimeAxisMap = Wasm.LinearTimeAxisMap;
export type Spectrogram = Wasm.Spectrogram;
export type SpectrogramVector = Wasm.SpectrogramVector;
export type Spectrum = Wasm.Spectrum;
export type StretchedPartialSpectrogram = Wasm.StretchedPartialSpectrogram;
export type SynthesizeWaveform = Wasm.SynthesizeWaveform;
export type SynthesizeWaveformWithWORLD = Wasm.SynthesizeWaveformWithWORLD;
export type Waveform = Wasm.Waveform;
export type WaveformSpectrogram = Wasm.WaveformSpectrogram;
