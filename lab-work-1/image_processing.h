// image_processing.h
#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include "bmp.h"
#include <vector>

// Функции для обработки изображений
void rotate90Clockwise(int width, int height, const std::vector<Pixel> &src, std::vector<Pixel> &dst);
void rotate90CounterClockwise(int width, int height, const std::vector<Pixel> &src, std::vector<Pixel> &dst);
std::vector<float> gaussianKernel(int size, float sigma);
Pixel applyGaussianFilter(const std::vector<Pixel> &image, int width, int height, int x, int y, const std::vector<float> &kernel, int kernelSize);
void applyGaussianFilterToImage(const std::vector<Pixel> &src, int width, int height, std::vector<Pixel> &dst, const std::vector<float> &kernel, int kernelSize);

#endif // IMAGE_PROCESSING_H

