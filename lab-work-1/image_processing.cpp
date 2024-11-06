// image_processing.cpp
#include "image_processing.h"
#include <cmath>

void rotate90Clockwise(int width, int height, const std::vector<Pixel> &src, std::vector<Pixel> &dst) {
    dst.resize(width * height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            dst[x * height + (height - 1 - y)] = src[y * width + x];
        }
    }
}

void rotate90CounterClockwise(int width, int height, const std::vector<Pixel> &src, std::vector<Pixel> &dst) {
    dst.resize(width * height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            dst[(width - 1 - x) * height + y] = src[y * width + x];
        }
    }
}

std::vector<float> gaussianKernel(int size, float sigma) {
    std::vector<float> kernel(size * size);
    float sum = 0.0f;
    int radius = size / 2;
    float twoSigmaSquare = 2.0f * sigma * sigma;

    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            kernel[(i + radius) * size + (j + radius)] = exp(-(i * i + j * j) / twoSigmaSquare);
            sum += kernel[(i + radius) * size + (j + radius)];
        }
    }

    // Нормализация ядра
    for (float &val : kernel) {
        val /= sum;
    }

    return kernel;
}

Pixel applyGaussianFilter(const std::vector<Pixel> &image, int width, int height, int x, int y, const std::vector<float> &kernel, int kernelSize) {
    float r = 0.0f, g = 0.0f, b = 0.0f;
    int radius = kernelSize / 2;

    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            int px = x + i;
            int py = y + j;
            if (px >= 0 && px < width && py >= 0 && py < height) {
                int idx = py * width + px;
                int kIdx = (i + radius) * kernelSize + (j + radius);
                r += image[idx].red * kernel[kIdx];
                g += image[idx].green * kernel[kIdx];
                b += image[idx].blue * kernel[kIdx];
            }
        }
    }

    return Pixel{static_cast<uint8_t>(std::min(std::max(r, 0.0f), 255.0f)),
                 static_cast<uint8_t>(std::min(std::max(g, 0.0f), 255.0f)),
                 static_cast<uint8_t>(std::min(std::max(b, 0.0f), 255.0f))};
}

void applyGaussianFilterToImage(const std::vector<Pixel> &src, int width, int height, std::vector<Pixel> &dst, const std::vector<float> &kernel, int kernelSize) {
    dst.resize(src.size());
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            dst[y * width + x] = applyGaussianFilter(src, width, height, x, y, kernel, kernelSize);
        }
    }
}

