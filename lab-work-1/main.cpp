#include <iostream>
#include "bmp.h"
#include "image_processing.h"

int main() {
    std::cout << "Input file name: ";
    std::string inputFile;
    std::cin >> inputFile;
    std::string outputFileGaussian = "output_gaussian.bmp";
    std::string outputRotateR = "output_clockwise.bmp";
    std::string outputRotateL = "output_counterclockwise.bmp";

    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    std::vector<Pixel> pixels;

    // Загрузка BMP
    loadBMP(inputFile, bmpHeader, dibHeader, pixels);
    if (pixels.empty()) {
        std::cerr << "Failed to load image!" << std::endl;
        return 1;
    }

    // Поворот по часовой стрелке
    std::vector<Pixel> rotatedImageClockwise;
    rotate90Clockwise(dibHeader.width, dibHeader.height, pixels, rotatedImageClockwise);
    saveBMP(outputRotateR, bmpHeader, dibHeader, rotatedImageClockwise);

    // Поворот против часовой стрелки
    std::vector<Pixel> rotatedImageCounterClockwise;
    rotate90CounterClockwise(dibHeader.width, dibHeader.height, pixels, rotatedImageCounterClockwise);
    saveBMP(outputRotateL, bmpHeader, dibHeader, rotatedImageCounterClockwise);

    // Применение Гауссовского фильтра
    int kernelSize = 5;
    float sigma = 1.0f;
    std::vector<float> kernel = gaussianKernel(kernelSize, sigma);

    std::vector<Pixel> filteredImage;
    applyGaussianFilterToImage(pixels, dibHeader.width, dibHeader.height, filteredImage, kernel, kernelSize);

    // Сохранение отфильтрованного изображения
    saveBMP(outputFileGaussian, bmpHeader, dibHeader, filteredImage);

    std::cout << "Image processing completed!" << std::endl;
    return 0;
}

