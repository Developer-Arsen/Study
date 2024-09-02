import React, { useEffect, useRef, useState } from 'react';

const BlurImage = () => {
  const [appliedFilter, setAppliedFilter] = useState(null);
  const imgRef = useRef(null);
  const canvasRef = useRef(null);
  const wasmInstanceRef = useRef(null);

  useEffect(() => {
    const loadWasm = async () => {
      try {
        const response = await fetch('./filters.wasm');
        const bytes = await response.arrayBuffer();
        const { instance } = await WebAssembly.instantiate(bytes, {});
        wasmInstanceRef.current = instance;
      } catch (error) {
        console.error('Failed to load WASM module:', error);
      }
    };
    loadWasm();
  }, []);

  const applyWasmFilter = (filterFunc) => {
    if (!wasmInstanceRef.current) {
      console.error('WASM instance not loaded');
      return;
    }

    const canvas = canvasRef.current;
    const ctx = canvas.getContext('2d');
    const img = imgRef.current;

    canvas.width = img.width;
    canvas.height = img.height;

    ctx.drawImage(img, 0, 0, img.width, img.height);
    const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
    const pixels = new Uint8Array(imageData.data.buffer);

    const wasmMemory = wasmInstanceRef.current.exports.memory;
    const wasmPixelsPointer = wasmInstanceRef.current.exports.malloc(pixels.length);
    const wasmPixels = new Uint8Array(wasmMemory.buffer, wasmPixelsPointer, pixels.length);

    wasmPixels.set(pixels);

    console.time(`${filterFunc} WASM Filter`);
    wasmInstanceRef.current.exports[filterFunc](wasmPixelsPointer, canvas.width, canvas.height, 4);
    console.timeEnd(`${filterFunc} WASM Filter`);

    pixels.set(wasmPixels);
    wasmInstanceRef.current.exports.free(wasmPixelsPointer);

    ctx.putImageData(imageData, 0, 0);

    const filteredImageSrc = canvasRef.current.toDataURL();
    imgRef.current.src = filteredImageSrc;
    setAppliedFilter(filterFunc);
  };

  const resetImage = () => {
    imgRef.current.src = imgRef.current.dataset.originalSrc;
    setAppliedFilter(null);
  };

  return (
    <div style={{ textAlign: 'center', marginTop: '50px' }}>
      <img
        ref={imgRef}
        src="http://127.0.0.1:3006/cdn/66d46ad0ad59bad96085c1e4"
        data-original-src="http://127.0.0.1:3006/cdn/66d46ad0ad59bad96085c1e4"
        crossOrigin="anonymous"
        alt="Example"
        style={{
          width: '300px',
          height: '300px',
          display: 'block',
          margin: '0 auto',
        }}
      />
      <canvas
        ref={canvasRef}
        style={{ display: 'none' }}
      ></canvas>
      <div>
        <button
          onClick={() => applyWasmFilter('gaussian_blur')}
          style={{
            marginTop: '20px',
            padding: '10px 20px',
            fontSize: '16px',
            cursor: 'pointer',
            backgroundColor: '#007bff',
            color: 'white',
            border: 'none',
            borderRadius: '5px',
            marginRight: '10px',
          }}
        >
          Apply Gaussian Blur
        </button>
        <button
          onClick={() => applyWasmFilter('grayscale_filter')}
          style={{
            marginTop: '20px',
            padding: '10px 20px',
            fontSize: '16px',
            cursor: 'pointer',
            backgroundColor: '#28a745',
            color: 'white',
            border: 'none',
            borderRadius: '5px',
            marginRight: '10px',
          }}
        >
          Apply Grayscale
        </button>
        <button
          onClick={() => applyWasmFilter('invert_colors')}
          style={{
            marginTop: '20px',
            padding: '10px 20px',
            fontSize: '16px',
            cursor: 'pointer',
            backgroundColor: '#dc3545',
            color: 'white',
            border: 'none',
            borderRadius: '5px',
            marginRight: '10px',
          }}
        >
          Apply Invert Colors
        </button>
        <button
          onClick={() => applyWasmFilter('sepia_filter')}
          style={{
            marginTop: '20px',
            padding: '10px 20px',
            fontSize: '16px',
            cursor: 'pointer',
            backgroundColor: '#ffc107',
            color: 'white',
            border: 'none',
            borderRadius: '5px',
            marginRight: '10px',
          }}
        >
          Apply Sepia
        </button>
        <button
          onClick={resetImage}
          style={{
            marginTop: '20px',
            padding: '10px 20px',
            fontSize: '16px',
            cursor: 'pointer',
            backgroundColor: '#6c757d',
            color: 'white',
            border: 'none',
            borderRadius: '5px',
          }}
        >
          Reset Image
        </button>
      </div>
      {appliedFilter && <p style={{ marginTop: '20px' }}>Applied filter: {appliedFilter.replace('_', ' ')}</p>}
    </div>
  );
};

export default BlurImage;
