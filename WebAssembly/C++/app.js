document.getElementById('apply-blur').addEventListener('click', () => {
    const input = document.getElementById('upload');
    if (!input.files.length) return;

    const file = input.files[0];
    const img = new Image();
    const canvas = document.getElementById('canvas');
    const ctx = canvas.getContext('2d');

    img.onload = () => {
        canvas.width = img.width;
        canvas.height = img.height;
        ctx.drawImage(img, 0, 0);

        const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);

        // Ensure the WebAssembly module is fully initialized
        Module.onRuntimeInitialized = () => {
            console.log("WebAssembly module initialized");

            // Get the functions from the Module object
            const _malloc = Module._malloc;
            const _free = Module._free;
            const _gaussian_blur = Module._gaussian_blur;
            const HEAPU8 = Module.HEAPU8;

            const imagePtr = _malloc(imageData.data.length);
            const outputPtr = _malloc(imageData.data.length);

            HEAPU8.set(imageData.data, imagePtr);
            _gaussian_blur(imagePtr, outputPtr, imageData.width, imageData.height);

            const blurredData = HEAPU8.subarray(outputPtr, outputPtr + imageData.data.length);
            ctx.putImageData(new ImageData(new Uint8ClampedArray(blurredData), imageData.width, imageData.height), 0, 0);

            _free(imagePtr);
            _free(outputPtr);

            // Save the canvas as an image file
            const link = document.createElement('a');
            link.href = canvas.toDataURL('image/png');
            link.download = 'blurred_image.png';
            link.click();
        };

        if (Module._gaussian_blur) {
            // Module is already initialized
            Module.onRuntimeInitialized();
        }
    };

    img.src = URL.createObjectURL(file);
});
