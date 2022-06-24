# uzumejs

uzumejs is a thin wrapper of [uzume_vocoder](https://github.com/haruneko/uzume_vocoder).
[uzume_vocoder](https://github.com/haruneko/uzume_vocoder) is a WORLD, vocoder, implementation.
WORLD is high-quality speech analysis, manipulation and synthesis system by mmorise. See more: https://github.com/mmorise/World

# usage

## nodejs

Install uzumejs.

```sh
npm i uzumejs
```

Then use like below (need [node-wav](https://www.npmjs.com/package/node-wav)):

```ts
import uzumejs from "uzumejs"
import wave from "node-wav";
import * as fs from "fs"

console.log(process.argv);
uzumejs().then(uzume => {
    const buf = fs.readFileSync("./vaiueo2d.wav");
    const w = wave.decode(buf);
    const wf = uzume.CreateWaveformFrom(w.channelData[0], w.sampleRate);
    if(wf !== null) {
        const out = new uzume.Waveform(wf.length, wf.samplingFrequency);
        const spec = new uzume.WaveformSpectrogram(wf);
        const synth = new uzume.SynthesizeWaveformWithWORLD();
        synth.synthesize(out, spec);
        let b = wave.encode(new Array(uzume.ArrayFromWaveform(out)), {sampleRate: w.sampleRate});
        fs.writeFileSync("./vaiueo_resynth.wav", b);
        wf.delete();
        spec.delete();
        synth.delete();
    }
})
```

## webpack

Install uzumejs.

```sh
npm i uzumejs
```

Change webpack.config.js.

```js
module.exports = {
    webpack: {
        configure:{
            // See https://github.com/webpack/webpack/issues/6725
            module:{
                rules: [{
                    test: /\.wasm$/,
                    type: 'javascript/auto',
                }]
            },
            resolve:{
                fallback: { "path": false, "fs": false }
            }
        }
    }
};
```

Use like this.

```ts
  const audioContext = useRef<AudioContext>(null!);
  const [audioBuffer, setAudioBuffer] = useState<AudioBuffer>(null!);

  useEffect(() => { audioContext.current = new AudioContext(); }, []);

  const handleChangeFile: React.ChangeEventHandler<HTMLInputElement> = async (e) => {
    const file = e?.target?.files?.item(0);
    let _audioBuffer: AudioBuffer | null = null;
    if(file !== null && file !== undefined) {
      _audioBuffer = await audioContext.current.decodeAudioData(
        await file.arrayBuffer()
      );
      setAudioBuffer(_audioBuffer); // 追加
    }
    const u = await uzume({ locateFile: () => uzumejsWasm });
    if(_audioBuffer != null) {
      const w = u.CreateWaveformFrom(_audioBuffer.getChannelData(0), _audioBuffer.sampleRate);
      console.log(_audioBuffer.length, _audioBuffer.sampleRate);
      if(w != null ){
        const sp = new u.WaveformSpectrogram(w);
        const out = new u.Waveform(w.length, w.samplingFrequency);
        const synthesis = new u.SynthesizeWaveformWithWORLD();
        synthesis.synthesize(out, sp);
        _audioBuffer.copyToChannel(u.ArrayFromWaveform(out), 0);
        synthesis.delete();
        sp.delete();
        out.delete();
      }
      console.log(w?.length);
      w?.delete();
    }
    console.log(file?.size);
  };
```

# License

MIT

# API

TBD

# development

Build and start docker before `npm build`

```
npm run docker:build
npm run docker:start
```

then

```
npm run build
```
