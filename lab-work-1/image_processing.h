#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include "bmp.h"
#include <vector>

// Function declarations for image processing operations
// Все ниже тоже следовало бы сделать методами. Возможно выделить в класс только гаусса и агрегировать
// его объект в картинку
// Rotates the image 90 degrees clockwise
void rotate90Clockwise(int width, int height, const std::vector<Pixel>& src, std::vector<Pixel>& dst);

// Rotates the image 90 degrees counter-clockwise
void rotate90CounterClockwise(int width, int height, const std::vector<Pixel>& src, std::vector<Pixel>& dst);

// Generates a Gaussian kernel for image filtering
std::vector<float> gaussianKernel(int size, float sigma);

// Applies a Gaussian filter to a single pixel
Pixel applyGaussianFilter(const std::vector<Pixel>& image, int width, int height, int x, int y, const std::vector<float>& kernel, int kernelSize);

// Applies the Gaussian filter to the entire image
void applyGaussianFilterToImage(const std::vector<Pixel>& src, int width, int height, std::vector<Pixel>& dst, const std::vector<float>& kernel, int kernelSize);

#endif // IMAGE_PROCESSING_H

