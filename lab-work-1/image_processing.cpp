#include "image_processing.h"
#include <cmath>
#include <thread>
#include <algorithm>
#include <iostream>

void rotate90Clockwise(int width, int height, const std::vector<Pixel>& src, 
                      std::vector<Pixel>& dst, unsigned num_threads) {
    dst.resize(width * height);
    
    const unsigned hardware_threads = std::thread::hardware_concurrency();
    const unsigned effective_threads = (num_threads == 0) ? hardware_threads : 
                                      std::min(num_threads, hardware_threads);
    
    if (width * height < 100000 || effective_threads <= 1) {
        for (int y = 0; y < height; ++y) {
            const Pixel* src_row = &src[y * width];
            for (int x = 0; x < width; ++x) {
                dst[x * height + (height - 1 - y)] = src_row[x];
            }
        }
        return;
    }

    std::vector<std::thread> threads;
    const int rows_per_thread = (height + effective_threads - 1) / effective_threads;

    auto process_rows = [&](int start_row, int end_row) {
        for (int y = start_row; y < end_row; ++y) {
            const Pixel* src_row = &src[y * width];
            for (int x = 0; x < width; ++x) {
                dst[x * height + (height - 1 - y)] = src_row[x];
            }
        }
    };

    for (unsigned i = 0; i < effective_threads; ++i) {
        int start_row = i * rows_per_thread;
        int end_row = std::min(start_row + rows_per_thread, height);
        threads.emplace_back(process_rows, start_row, end_row);
    }

    for (auto& t : threads) {
        t.join();
    }
}

void rotate90CounterClockwise(int width, int height, const std::vector<Pixel>& src, 
                             std::vector<Pixel>& dst, unsigned num_threads) {
    dst.resize(width * height);
    
    const unsigned hardware_threads = std::thread::hardware_concurrency();
    const unsigned effective_threads = (num_threads == 0) ? hardware_threads : 
                                     std::min(num_threads, hardware_threads);
    
    if (width * height < 100000 || effective_threads <= 1) {
        for (int y = 0; y < height; ++y) {
            const Pixel* src_row = &src[y * width];
            for (int x = 0; x < width; ++x) {
                dst[(width - 1 - x) * height + y] = src_row[x];
            }
        }
        return;
    }

    std::vector<std::thread> threads;
    const int rows_per_thread = (height + effective_threads - 1) / effective_threads;

    auto process_rows = [&](int start_row, int end_row) {
        for (int y = start_row; y < end_row; ++y) {
            const Pixel* src_row = &src[y * width];
            for (int x = 0; x < width; ++x) {
                dst[(width - 1 - x) * height + y] = src_row[x];
            }
        }
    };

    for (unsigned i = 0; i < effective_threads; ++i) {
        int start_row = i * rows_per_thread;
        int end_row = std::min(start_row + rows_per_thread, height);
        threads.emplace_back(process_rows, start_row, end_row);
    }

    for (auto& t : threads) {
        t.join();
    }
}

void applyGaussianFilterToImage(const std::vector<Pixel>& src, int width, int height,
                              std::vector<Pixel>& dst, const std::vector<float>& kernel,
                              int kernelSize, unsigned num_threads) {
    dst.resize(width * height);
    
    const unsigned hardware_threads = std::thread::hardware_concurrency();
    const unsigned effective_threads = (num_threads == 0) ? hardware_threads : 
                                     std::min(num_threads, hardware_threads);
    
    if (width * height < 100000 || effective_threads <= 1) {
        for (int y = 0; y < height; ++y) {
            Pixel* dst_row = &dst[y * width];
            for (int x = 0; x < width; ++x) {
                const int radius = kernelSize / 2;
                float blue = 0.0f, green = 0.0f, red = 0.0f;

                for (int ky = -radius; ky <= radius; ++ky) {
                    const int py = std::clamp(y + ky, 0, height - 1);
                    const Pixel* src_row = &src[py * width];
                    const float* k_row = &kernel[(ky + radius) * kernelSize];
                    
                    for (int kx = -radius; kx <= radius; ++kx) {
                        const int px = std::clamp(x + kx, 0, width - 1);
                        const float weight = k_row[kx + radius];
                        blue += src_row[px].blue * weight;
                        green += src_row[px].green * weight;
                        red += src_row[px].red * weight;
                    }
                }

                dst_row[x] = {
                    static_cast<uint8_t>(std::clamp(blue, 0.0f, 255.0f)),
                    static_cast<uint8_t>(std::clamp(green, 0.0f, 255.0f)),
                    static_cast<uint8_t>(std::clamp(red, 0.0f, 255.0f))
                };
            }
        }
        return;
    }

    std::vector<std::thread> threads;
    const int rows_per_thread = (height + effective_threads - 1) / effective_threads;

    auto process_rows = [&](int start_row, int end_row) {
        for (int y = start_row; y < end_row; ++y) {
            Pixel* dst_row = &dst[y * width];
            for (int x = 0; x < width; ++x) {
                const int radius = kernelSize / 2;
                float blue = 0.0f, green = 0.0f, red = 0.0f;

                for (int ky = -radius; ky <= radius; ++ky) {
                    const int py = std::clamp(y + ky, 0, height - 1);
                    const Pixel* src_row = &src[py * width];
                    const float* k_row = &kernel[(ky + radius) * kernelSize];
                    
                    for (int kx = -radius; kx <= radius; ++kx) {
                        const int px = std::clamp(x + kx, 0, width - 1);
                        const float weight = k_row[kx + radius];
                        blue += src_row[px].blue * weight;
                        green += src_row[px].green * weight;
                        red += src_row[px].red * weight;
                    }
                }

                dst_row[x] = {
                    static_cast<uint8_t>(std::clamp(blue, 0.0f, 255.0f)),
                    static_cast<uint8_t>(std::clamp(green, 0.0f, 255.0f)),
                    static_cast<uint8_t>(std::clamp(red, 0.0f, 255.0f))
                };
            }
        }
    };

    for (unsigned i = 0; i < effective_threads; ++i) {
        int start_row = i * rows_per_thread;
        int end_row = std::min(start_row + rows_per_thread, height);
        threads.emplace_back(process_rows, start_row, end_row);
    }

    for (auto& t : threads) {
        t.join();
    }
}

std::vector<float> gaussianKernel(int size, float sigma) {
    std::vector<float> kernel(size * size);
    const int radius = size / 2;
    const float twoSigmaSq = 2.0f * sigma * sigma;
    float sum = 0.0f;

    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            float val = exp(-(i*i + j*j) / twoSigmaSq);
            kernel[(i + radius) * size + (j + radius)] = val;
            sum += val;
        }
    }

    for (float& val : kernel) {
        val /= sum;
    }

    return kernel;
}
