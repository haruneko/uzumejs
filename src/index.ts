import * as Wasm from "../resources/uzumewasm";
import { UzumeJs, UzumeJsImpl } from "./uzumejs";

const uzumejs: (...args: any[]) => Promise<UzumeJs> = (args) => {
    const js = require("../resources/uzumewasm.js");
    console.log(js);
    const ret: Promise<UzumeJs> = js(args).then((v: Wasm.CustomEmbindModule) => new UzumeJsImpl(v));
    return ret;
}

export default uzumejs;
export * from "../resources/uzumewasm"
