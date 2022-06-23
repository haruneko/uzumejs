import { CustomEmbindModule } from "../resources/uzumewasm";
import { UzumeJs, UzumeJsImpl } from "./uzumejs";

const uzumejs: () => Promise<UzumeJs> = () => {
    const js = require("../resources/uzumewasm.js");
    const ret: Promise<UzumeJs> = js().then((v: CustomEmbindModule) => new UzumeJsImpl(v));
    return ret;
}

export default uzumejs;
