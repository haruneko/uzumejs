import { assert } from 'console';
import uzumejs from '../dist/index';

describe('uzumejs', () => {
  it('should return an object that has exported functions from wasm', async () => {
    const uzume = await uzumejs();
    // constructor test only, because JavaScript is a thin wrapper of C++.
    const contour = new uzume.Contour(1000.0, 2.0);
    const waveform = new uzume.Waveform(44100, 44100);
    waveform.delete();
    contour.delete();
  });
  it('should create Waveform from JS Array and JS Array from Waveform', async () => {
    const uzume = await uzumejs();
    const data: Float32Array = new Float32Array(44100);
    for(let i = 0; i < 44100; i++) {
      data[i] = i < 22050 ? 0.0 : 1.0;
    }
    const waveform = uzume.CreateWaveformFrom(data, 44100);
    if(waveform === null) {
      fail("null waveform returned.");
    }
    expect(waveform.msLength()).toBe(1000.0);
    expect(waveform.at(22049)).toBe(0.0);
    expect(waveform.at(22050)).toBe(1.0);
    const arr = uzume.ArrayFromWaveform(waveform);
    expect(arr.length).toBe(44100);
    expect(arr[22049]).toBe(0.0);
    expect(arr[22050]).toBe(1.0);
    waveform.delete();
  })
});
