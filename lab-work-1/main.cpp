#include <iostream>
#include "bmp.h"
#include "image_processing.h"

int main() {
    // Запрос имени файла у пользователя
    std::cout << "Input file name: ";
    std::string inputFile;
    std::cin >> inputFile;

    // Имя выходных файлов для различных операций
    std::string outputFileGaussian = "output_gaussian.bmp";
    std::string outputRotateR = "output_clockwise.bmp";
    std::string outputRotateL = "output_counterclockwise.bmp";

    // Создание объекта BMPImage и загрузка изображения
    BMPImage bmpImage(inputFile);
    
    // Проверка успешности загрузки
    if (bmpImage.getPixels().empty()) {
        std::cerr << "Failed to load image!" << std::endl;
        return 1;
    }

    // Получение заголовка DIB
    DIBHeader dibHeader = bmpImage.getDIBHeader();
    std::vector<Pixel> pixels = bmpImage.getPixels();

    // Поворот изображения по часовой стрелке
    std::vector<Pixel> rotatedImageClockwise;
    rotate90Clockwise(dibHeader.width, dibHeader.height, pixels, rotatedImageClockwise);
    
    // Сохранение изображения после поворота по часовой стрелке
    bmpImage.setPixels(rotatedImageClockwise);  // Обновляем пиксели
    bmpImage.saveBMP(outputRotateR);

    // Поворот изображения против часовой стрелки
    std::vector<Pixel> rotatedImageCounterClockwise;
    rotate90CounterClockwise(dibHeader.width, dibHeader.height, pixels, rotatedImageCounterClockwise);
    
    // Сохранение изображения после поворота против часовой стрелки
    bmpImage.setPixels(rotatedImageCounterClockwise);  // Обновляем пиксели
    bmpImage.saveBMP(outputRotateL);

    // Применение Гауссовского фильтра
    int kernelSize = 5;
    float sigma = 1.0f;
    std::vector<float> kernel = gaussianKernel(kernelSize, sigma);

    std::vector<Pixel> filteredImage;
    applyGaussianFilterToImage(pixels, dibHeader.width, dibHeader.height, filteredImage, kernel, kernelSize);

    // Обновление пикселей отфильтрованного изображения и сохранение его
    bmpImage.setPixels(filteredImage);  // Обновляем пиксели
    bmpImage.saveBMP(outputFileGaussian);

    std::cout << "Image processing completed!" << std::endl;
    return 0;
}

