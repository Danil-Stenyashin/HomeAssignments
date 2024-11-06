// bmp.h
#ifndef BMP_H
#define BMP_H

#include <vector>
#include <string>

// Структуры для заголовков BMP
#pragma pack(push, 1)
struct BMPHeader {
    char signature[2];  // "BM"
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t dataOffset;
};

struct DIBHeader {
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t colorPlanes;
    uint16_t bpp; // bits per pixel (24 for RGB)
    uint32_t compression;
    uint32_t imageSize;
    int32_t xRes;
    int32_t yRes;
    uint32_t colorsUsed;
    uint32_t importantColors;
};
#pragma pack(pop)

// Структура для пикселя
struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

// Функции для загрузки и сохранения BMP
void loadBMP(const std::string &filename, BMPHeader &bmpHeader, DIBHeader &dibHeader, std::vector<Pixel> &pixels);
void saveBMP(const std::string &filename, const BMPHeader &bmpHeader, const DIBHeader &dibHeader, const std::vector<Pixel> &pixels);

#endif // BMP_H

