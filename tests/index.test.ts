import uzumejs from '../src';

describe('uzumejs init function', () => {
  it('should return an object that has exported functions from wasm', async () => {
    const uzume = await uzumejs();
    // constructor test only, because JavaScript is a thin wrapper of C++.
    const contour = new uzume.Contour(1000.0, 2.0);
    const waveform = new uzume.Waveform(44100, 44100);
    waveform.delete();
    contour.delete();
  });
});
