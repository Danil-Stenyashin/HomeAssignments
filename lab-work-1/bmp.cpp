// bmp.cpp
#include "bmp.h"
#include <fstream>
#include <iostream>

void loadBMP(const std::string &filename, BMPHeader &bmpHeader, DIBHeader &dibHeader, std::vector<Pixel> &pixels) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Чтение заголовков BMP
    file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
    if (bmpHeader.signature[0] != 'B' || bmpHeader.signature[1] != 'M') {
        std::cerr << "Not a valid BMP file!" << std::endl;
        return;
    }

    file.read(reinterpret_cast<char*>(&dibHeader), sizeof(dibHeader));

    // Выделяем память для пикселей
    pixels.resize(dibHeader.width * dibHeader.height);

    // Чтение данных о пикселях
    file.seekg(bmpHeader.dataOffset, std::ios::beg);
    file.read(reinterpret_cast<char*>(pixels.data()), dibHeader.width * dibHeader.height * sizeof(Pixel));
}

void saveBMP(const std::string &filename, const BMPHeader &bmpHeader, const DIBHeader &dibHeader, const std::vector<Pixel> &pixels) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    // Запись заголовков BMP
    file.write(reinterpret_cast<const char*>(&bmpHeader), sizeof(bmpHeader));
    file.write(reinterpret_cast<const char*>(&dibHeader), sizeof(dibHeader));

    // Запись данных о пикселях
    file.write(reinterpret_cast<const char*>(pixels.data()), dibHeader.width * dibHeader.height * sizeof(Pixel));
}

