import * as Wasm from "../resources/uzumewasm";
import { CreateUzumeJs, UzumeJs } from "./uzumejs";

const uzumejs: (...args: any[]) => Promise<UzumeJs> = (args) => {
    const js = require("../resources/uzumewasm.js");
    console.log(js);
    const ret: Promise<UzumeJs> = js(args).then((v: Wasm.CustomEmbindModule) => CreateUzumeJs(v));
    return ret;
}

export default uzumejs;
export * from "../resources/uzumewasm"
export * from "./uzumejs"
