const path = require("path");
const webpack = require("webpack");

const manager = {
    mode: "production",
    entry: "./src/index.ts",
    resolve: {
        fallback: {
            path: false,
            fs: false,
        },
    },
    module: {
        rules: [
            { test: [/\.ts$/], loader: "ts-loader" },
            { test: /\.wasm$/, type: "asset/inline" },
        ],
    },
    output: {
        filename: "index.js",
        path: path.resolve(__dirname, "dist"),
        libraryTarget: "umd",
        globalObject: "typeof self !== 'undefined' ? self : this",
    },
    stats: {
        children: true,
    },
    plugins: [
        new webpack.ProvidePlugin({
            Buffer: ["buffer", "Buffer"],
        }),
    ],
};

module.exports = [manager];
