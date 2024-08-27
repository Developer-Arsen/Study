// gaussian_blur.c
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

// Gaussian blur kernel
float kernel[5][5] = {
    {1/256.0, 4/256.0, 6/256.0, 4/256.0, 1/256.0},
    {4/256.0, 16/256.0, 24/256.0, 16/256.0, 4/256.0},
    {6/256.0, 24/256.0, 36/256.0, 24/256.0, 6/256.0},
    {4/256.0, 16/256.0, 24/256.0, 16/256.0, 4/256.0},
    {1/256.0, 4/256.0, 6/256.0, 4/256.0, 1/256.0}
};

void gaussian_blur(uint8_t* image, uint8_t* output, int width, int height) {
    int offset = 2; // Kernel radius
    for (int y = offset; y < height - offset; y++) {
        for (int x = offset; x < width - offset; x++) {
            float r = 0, g = 0, b = 0;
            for (int ky = -offset; ky <= offset; ky++) {
                for (int kx = -offset; kx <= offset; kx++) {
                    int pixelIndex = ((y + ky) * width + (x + kx)) * 4;
                    r += image[pixelIndex + 0] * kernel[ky + offset][kx + offset];
                    g += image[pixelIndex + 1] * kernel[ky + offset][kx + offset];
                    b += image[pixelIndex + 2] * kernel[ky + offset][kx + offset];
                }
            }
            int outputIndex = (y * width + x) * 4;
            output[outputIndex + 0] = (uint8_t)fmin(fmax(r, 0), 255);
            output[outputIndex + 1] = (uint8_t)fmin(fmax(g, 0), 255);
            output[outputIndex + 2] = (uint8_t)fmin(fmax(b, 0), 255);
            output[outputIndex + 3] = 255; // Full opacity
        }
    }
}
