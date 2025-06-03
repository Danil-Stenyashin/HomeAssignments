#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <vector>
#include "bmp.h"

const unsigned int DEFAULT_THREADS = std::thread::hardware_concurrency();


void rotate90Clockwise(int width, int height, const std::vector<Pixel>& src, std::vector<Pixel>& dst, unsigned int num_threads = DEFAULT_THREADS);


void rotate90CounterClockwise(int width, int height, const std::vector<Pixel>& src, std::vector<Pixel>& dst, unsigned int num_threads = DEFAULT_THREADS);

void applyGaussianFilterToImage(const std::vector<Pixel>& src, int width, int height, std::vector<Pixel>& dst, const std::vector<float>& kernel, int kernelSize, unsigned int num_threads = DEFAULT_THREADS);

std::vector<float> gaussianKernel(int size, float sigma);

Pixel applyGaussianFilter(const std::vector<Pixel>& image, int width, int height, int x, int y, const std::vector<float>& kernel, int kernelSize);

#endif // IMAGE_PROCESSING_H

