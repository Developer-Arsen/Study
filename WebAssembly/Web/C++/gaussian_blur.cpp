#include <cstdint>
#include <cstdlib>
#include <cmath>

const float kernel[5][5] = {
    {1/256.0f, 4/256.0f, 6/256.0f, 4/256.0f, 1/256.0f},
    {4/256.0f, 16/256.0f, 24/256.0f, 16/256.0f, 4/256.0f},
    {6/256.0f, 24/256.0f, 36/256.0f, 24/256.0f, 6/256.0f},
    {4/256.0f, 16/256.0f, 24/256.0f, 16/256.0f, 4/256.0f},
    {1/256.0f, 4/256.0f, 6/256.0f, 4/256.0f, 1/256.0f}
};

extern "C" {
    void gaussian_blur(uint8_t* image, uint8_t* output, int width, int height) {
        int offset = 2;
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
                output[outputIndex + 0] = static_cast<uint8_t>(std::fmin(std::fmax(r, 0.0f), 255.0f));
                output[outputIndex + 1] = static_cast<uint8_t>(std::fmin(std::fmax(g, 0.0f), 255.0f));
                output[outputIndex + 2] = static_cast<uint8_t>(std::fmin(std::fmax(b, 0.0f), 255.0f));
                output[outputIndex + 3] = 255;
            }
        }
    }
}
