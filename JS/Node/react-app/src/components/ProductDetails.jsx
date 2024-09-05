import axios from 'axios';
import React, { useRef, useState, useEffect } from 'react';
import { useParams } from 'react-router-dom';

const protocol = window.location.protocol;
const hostname = window.location.hostname;
const protocolAndHostname = `${protocol}//${hostname}`;
const productsFetch = protocolAndHostname + ":3006/products/";
const cdnPost = protocolAndHostname + ":3006/cdn/";

const ProductDetails = ({ }) => {
    const { productId } = useParams();

    const [appliedFilter, setAppliedFilter] = useState(null);
    const [product, setProduct] = useState({});

    const imgRef = useRef(null);
    const canvasRef = useRef(null);
    const wasmInstanceRef = useRef(null);

    useEffect(() => {
        async function fetchData() {
            try {
                let response = await fetch(productsFetch + productId);
                const data = await response.json();
                setProduct(data);
                console.log(data);

            } catch (error) {
                console.error('Error fetching data:', error);
            }
        }
        fetchData();
    }, [])

    useEffect(() => {
        const loadWasm = async () => {
            try {
                const response = await fetch('/filters.wasm');
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

    const saveImage = async () => {
        const image = canvasRef.current.toDataURL();
        let photoId = product.url.split("/")[4];
        

        if (image) {
            // const formData = new FormData();
            // formData.append("image", image);
            try {
                await axios.post(cdnPost + photoId, {image}, {
                    headers: {
                        "Content-Type": "application/json"
                    }
                });

            } catch (error) {
                console.error("There was an error adding the product:", error);
            }
        }
    }

    return (
        <div className="product">
            <h3>{product.name}</h3>
            <p>Price: ${product.price}</p>
            <canvas
                ref={canvasRef}
                style={{ display: 'none' }}
            ></canvas>
            <img
                ref={imgRef}
                src={product.url}
                data-original-src={product.url}
                crossOrigin="anonymous"
                alt={product.name}
                style={{
                    width: '150px',
                    height: '150px',
                    display: 'block',
                    margin: '0 auto',
                }}
            />
            <div style={{ marginTop: '10px' }}>
                <button onClick={() => applyWasmFilter('gaussian_blur')} className="filter-btn">
                    Gaussian Blur
                </button>
                <button onClick={() => applyWasmFilter('grayscale_filter')} className="filter-btn">
                    Grayscale
                </button>
                <button onClick={() => applyWasmFilter('invert_colors')} className="filter-btn">
                    Invert Colors
                </button>
                <button onClick={() => applyWasmFilter('sepia_filter')} className="filter-btn">
                    Sepia
                </button>
                <button onClick={resetImage} className="filter-btn reset-btn">
                    Reset
                </button>
                <button onClick={saveImage} className="btn btn-success filter-btn">
                    Save Image
                </button>
            </div>
            {appliedFilter && <p>Applied filter: {appliedFilter.replace('_', ' ')}</p>}
        </div>
    );
};

export default ProductDetails;
