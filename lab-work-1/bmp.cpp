#include "bmp.h"
#include <fstream>
#include <iostream>

// Конструктор, который загружает BMP файл при создании объекта
BMPImage::BMPImage(const std::string& filename) {
    loadBMP(filename);  // Загружаем BMP файл при создании объекта
}

// Функция для загрузки BMP файла
void BMPImage::loadBMP(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening BMP file!" << std::endl;
        return;
    }

    // Чтение BMP и DIB заголовков
    file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
    if (bmpHeader.signature[0] != 'B' || bmpHeader.signature[1] != 'M') {
        std::cerr << "Invalid BMP file format!" << std::endl;
        return;
    }

    file.read(reinterpret_cast<char*>(&dibHeader), sizeof(dibHeader));
    if (dibHeader.bpp != 24) {  // Проверка на поддерживаемый формат (24-бит)
        std::cerr << "Only 24-bit BMP images are supported!" << std::endl;
        return;
    }

    // Расчет размера строки с учетом паддинга
    size_t rowSize = dibHeader.width * 3 + (4 - (dibHeader.width * 3) % 4) % 4;
    pixels.resize(dibHeader.width * dibHeader.height);

    // Перемещение указателя в файл на начало пиксельных данных
    file.seekg(bmpHeader.dataOffset, std::ios::beg);

    // Чтение данных пикселей, начиная с нижней строки (BMP хранит изображения снизу вверх)
    for (int y = dibHeader.height - 1; y >= 0; --y) {
        file.read(reinterpret_cast<char*>(&pixels[y * dibHeader.width]), dibHeader.width * 3);
        file.seekg(rowSize - dibHeader.width * 3, std::ios::cur); // Паддинг
    }
}

// Функция для сохранения BMP файла
void BMPImage::saveBMP(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening BMP file for writing!" << std::endl;
        return;
    }

    // Запись BMP и DIB заголовков
    file.write(reinterpret_cast<const char*>(&bmpHeader), sizeof(bmpHeader));
    file.write(reinterpret_cast<const char*>(&dibHeader), sizeof(dibHeader));

    // Расчет размера строки с учетом паддинга
    size_t rowSize = dibHeader.width * 3 + (4 - (dibHeader.width * 3) % 4) % 4;
    
    // Запись данных пикселей, начиная с нижней строки (BMP хранит изображения снизу вверх)
    for (int y = dibHeader.height - 1; y >= 0; --y) {
        file.write(reinterpret_cast<const char*>(&pixels[y * dibHeader.width]), dibHeader.width * 3);
        uint8_t padding[3] = {0, 0, 0};  // Добавление паддинга
        file.write(reinterpret_cast<const char*>(&padding), rowSize - dibHeader.width * 3);
    }
}

// Геттер для пикселей
const std::vector<Pixel>& BMPImage::getPixels() const {
    return pixels;
}

// Сеттер для пикселей
void BMPImage::setPixels(const std::vector<Pixel>& newPixels) {
    pixels = newPixels;
}

// Геттер для DIB заголовка
const DIBHeader& BMPImage::getDIBHeader() const {
    return dibHeader;
}

// Геттер для BMP заголовка
const BMPHeader& BMPImage::getBMPHeader() const {
    return bmpHeader;
}

