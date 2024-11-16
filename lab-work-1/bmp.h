#ifndef BMP_H
#define BMP_H

#include <vector>
#include <string>

// BMP Header Structure
// These structures define the layout of the BMP file and DIB header
#pragma pack(push, 1)
struct BMPHeader {
    char signature[2];  // "BM" (2 bytes)
    uint32_t fileSize;  // File size (4 bytes)
    uint32_t reserved;  // Reserved field (4 bytes)
    uint32_t dataOffset; // Offset to the pixel data (4 bytes)
};

struct DIBHeader {
    uint32_t headerSize;  // Size of this header (4 bytes)
    int32_t width;        // Image width in pixels (4 bytes)
    int32_t height;       // Image height in pixels (4 bytes)
    uint16_t colorPlanes; // Number of color planes (always 1) (2 bytes)
    uint16_t bpp;         // Bits per pixel (usually 24 for RGB) (2 bytes)
    uint32_t compression; // Compression type (4 bytes)
    uint32_t imageSize;   // Image size (4 bytes)
    int32_t xRes;         // Horizontal resolution (4 bytes)
    int32_t yRes;         // Vertical resolution (4 bytes)
    uint32_t colorsUsed;  // Number of colors used (4 bytes)
    uint32_t importantColors; // Number of important colors (4 bytes)
};
#pragma pack(pop)

// Pixel structure (representing one pixel in BGR format)
struct Pixel {
    uint8_t blue;   // Blue channel (1 byte)
    uint8_t green;  // Green channel (1 byte)
    uint8_t red;    // Red channel (1 byte)
};
// Очень много параметров и отсутствие инкапсуляции. Это следовало сделать методами класса картинки
// И почти все эти параметры стали бы полями этого класса
// Function declarations
void loadBMP(const std::string& filename, BMPHeader& bmpHeader, DIBHeader& dibHeader, std::vector<Pixel>& pixels);
void saveBMP(const std::string& filename, const BMPHeader& bmpHeader, const DIBHeader& dibHeader, const std::vector<Pixel>& pixels);

#endif // BMP_H

