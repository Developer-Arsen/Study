const fs = require('fs');
const path = require('path');

const Module = require('./socket_app.js');

const wasmFilePath = path.join(__dirname, 'socket_app.wasm');
const wasmBinary = fs.readFileSync(wasmFilePath);

Module({
    instantiateWasm: (imports, successCallback) => {
        WebAssembly.instantiate(wasmBinary, imports)
            .then(output => {
                const { _send_data, _malloc, _free } = output.instance.exports;

                if (!_send_data || !_malloc || !_free) {
                    console.error('WASM functions not found');
                    return;
                }
            }
            )
            .catch(err => console.error('WASM instantiation failed:', err));
    },

    onRuntimeInitialized: function () {
        console.log('WASM Runtime Initialized');
    }
});
