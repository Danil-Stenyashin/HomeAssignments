#include "image_processing.h"
#include <cmath>

// Rotate the image 90 degrees clockwise
// Takes the source image (src), rotates it, and stores the result in dst.
void rotate90Clockwise(int width, int height, const std::vector<Pixel>& src, std::vector<Pixel>& dst) {
    dst.resize(width * height); // Resize destination to fit rotated image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            dst[x * height + (height - 1 - y)] = src[y * width + x]; // Assign pixel in rotated position
        }
    }
}

// Rotate the image 90 degrees counter-clockwise
void rotate90CounterClockwise(int width, int height, const std::vector<Pixel>& src, std::vector<Pixel>& dst) {
    dst.resize(width * height); // Resize destination to fit rotated image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            dst[(width - 1 - x) * height + y] = src[y * width + x]; // Assign pixel in rotated position
        }
    }
}

// Generate a Gaussian kernel for filtering
// The kernel size and standard deviation (sigma) are provided as parameters.
std::vector<float> gaussianKernel(int size, float sigma) {
    std::vector<float> kernel(size * size); // Kernel size is size x size
    float sum = 0.0f;
    int radius = size / 2; // Radius is half the kernel size
    float twoSigmaSquare = 2.0f * sigma * sigma;

    // Fill the kernel with Gaussian values
    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            kernel[(i + radius) * size + (j + radius)] = exp(-(i * i + j * j) / twoSigmaSquare); // Gaussian formula
            sum += kernel[(i + radius) * size + (j + radius)];
        }
    }

    // Normalize the kernel so that the sum of all elements is 1
    for (float& val : kernel) {
        val /= sum;
    }

    return kernel;
}

// Apply the Gaussian filter to a single pixel
Pixel applyGaussianFilter(const std::vector<Pixel>& image, int width, int height, int x, int y, const std::vector<float>& kernel, int kernelSize) {
    int radius = kernelSize / 2;
    float blue = 0.0f, green = 0.0f, red = 0.0f;

    for (int ky = -radius; ky <= radius; ++ky) {
        for (int kx = -radius; kx <= radius; ++kx) {
            int pixelX = std::min(std::max(x + kx, 0), width - 1);
            int pixelY = std::min(std::max(y + ky, 0), height - 1);
            float weight = kernel[(ky + radius) * kernelSize + (kx + radius)];
            const Pixel& pixel = image[pixelY * width + pixelX];
            blue += pixel.blue * weight;
            green += pixel.green * weight;
            red += pixel.red * weight;
        }
    }

    return Pixel{static_cast<uint8_t>(blue), static_cast<uint8_t>(green), static_cast<uint8_t>(red)};
}

// Apply the Gaussian filter to the entire image
void applyGaussianFilterToImage(const std::vector<Pixel>& src, int width, int height, std::vector<Pixel>& dst, const std::vector<float>& kernel, int kernelSize) {
    dst.resize(width * height); // Resize destination to fit filtered image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            dst[y * width + x] = applyGaussianFilter(src, width, height, x, y, kernel, kernelSize); // Apply filter to each pixel
        }
    }
}

