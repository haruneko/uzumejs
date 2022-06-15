import { CustomEmbindModule } from "../resources/uzumewasm";

// @ts-ignore
import uzumejswasm from "../resources/uzumewasm.wasm";

const uzumejs: () => Promise<CustomEmbindModule> = () => {
    const js = require("../resources/uzumewasm.js");
    const b = Buffer.from(uzumejswasm.split(",")[1]!, "base64");
    return js({wasmBinary: b});
}
export default uzumejs;
