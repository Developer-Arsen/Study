import React, { useState, useEffect } from 'react';

const SumComponent = () => {
  const [wasmModule, setWasmModule] = useState(null);
  const [result, setResult] = useState(null);

  useEffect(() => {
    const loadWasm = async () => {
      try {
        const wasm = await fetch('./sum.wasm'); // Adjust the path if necessary
        const buffer = await wasm.arrayBuffer();
        const { instance } = await WebAssembly.instantiate(buffer);
        setWasmModule(instance.exports);
      } catch (error) {
        console.error('Failed to load Wasm module:', error);
      }
    };

    loadWasm();
  }, []);

  const calculateSum = () => {
    if (wasmModule) {
      const sumResult = wasmModule.sum(); // Call the sum function from C
      console.log(sumResult);
      
      // setResult(sumResult);
    }
  };

  return (
    <div>
      <button onClick={calculateSum}>Calculate Sum</button>
      {result !== null && <p>Result: {result}</p>}
    </div>
  );
};

export default SumComponent;
