#include <stdint.h>
#include <stdlib.h>
#include <math.h>

// Gaussian Blur
void gaussian_blur(uint8_t *pixels, int width, int height, int stride) {
    int kernel[5][5] = {
        {1, 4, 7, 4, 1},
        {4, 16, 26, 16, 4},
        {7, 26, 41, 26, 7},
        {4, 16, 26, 16, 4},
        {1, 4, 7, 4, 1}
    };
    int kernelSum = 273;
    int halfKernelSize = 2;

    uint8_t *tempPixels = (uint8_t *)malloc(width * height * stride);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = 0, g = 0, b = 0;

            for (int ky = 0; ky < 5; ky++) {
                for (int kx = 0; kx < 5; kx++) {
                    int px = x + kx - halfKernelSize;
                    int py = y + ky - halfKernelSize;

                    if (px >= 0 && px < width && py >= 0 && py < height) {
                        int offset = (py * width + px) * stride;
                        int weight = kernel[ky][kx];

                        r += pixels[offset] * weight;
                        g += pixels[offset + 1] * weight;
                        b += pixels[offset + 2] * weight;
                    }
                }
            }

            int offset = (y * width + x) * stride;
            tempPixels[offset] = r / kernelSum;
            tempPixels[offset + 1] = g / kernelSum;
            tempPixels[offset + 2] = b / kernelSum;
            tempPixels[offset + 3] = pixels[offset + 3]; // Preserve alpha channel
        }
    }

    for (int i = 0; i < width * height * stride; i++) {
        pixels[i] = tempPixels[i];
    }

    free(tempPixels);
}

// Grayscale Filter
void grayscale_filter(uint8_t *pixels, int width, int height, int stride) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int offset = (y * width + x) * stride;
            uint8_t r = pixels[offset];
            uint8_t g = pixels[offset + 1];
            uint8_t b = pixels[offset + 2];
            uint8_t gray = (r + g + b) / 3;
            pixels[offset] = gray;
            pixels[offset + 1] = gray;
            pixels[offset + 2] = gray;
        }
    }
}

// Invert Colors Filter
void invert_colors(uint8_t *pixels, int width, int height, int stride) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int offset = (y * width + x) * stride;
            pixels[offset] = 255 - pixels[offset];       // Red
            pixels[offset + 1] = 255 - pixels[offset + 1]; // Green
            pixels[offset + 2] = 255 - pixels[offset + 2]; // Blue
        }
    }
}

// Sepia Filter
void sepia_filter(uint8_t *pixels, int width, int height, int stride) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int offset = (y * width + x) * stride;
            uint8_t r = pixels[offset];
            uint8_t g = pixels[offset + 1];
            uint8_t b = pixels[offset + 2];

            uint8_t tr = (uint8_t)fmin((0.393 * r + 0.769 * g + 0.189 * b), 255.0);
            uint8_t tg = (uint8_t)fmin((0.349 * r + 0.686 * g + 0.168 * b), 255.0);
            uint8_t tb = (uint8_t)fmin((0.272 * r + 0.534 * g + 0.131 * b), 255.0);

            pixels[offset] = tr;
            pixels[offset + 1] = tg;
            pixels[offset + 2] = tb;
        }
    }
}

// Brightness Adjustment
void adjust_brightness(uint8_t *pixels, int width, int height, int stride, int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int offset = (y * width + x) * stride;
            pixels[offset] = fmin(fmax(pixels[offset] + brightness, 0), 255);
            pixels[offset + 1] = fmin(fmax(pixels[offset + 1] + brightness, 0), 255);
            pixels[offset + 2] = fmin(fmax(pixels[offset + 2] + brightness, 0), 255);
        }
    }
}
