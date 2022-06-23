import { CustomEmbindModule } from "../resources/uzumewasm";
import { UzumeJs, UzumeJsImpl } from "./uzumejs";

const uzumejs: (...args: any[]) => Promise<UzumeJs> = (args) => {
    const js = require("../resources/uzumewasm.js");
    console.log(js);
    const ret: Promise<UzumeJs> = js(args).then((v: CustomEmbindModule) => new UzumeJsImpl(v));
    return ret;
}

export default uzumejs;
