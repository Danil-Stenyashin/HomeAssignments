#include "bmp.h"
#include <fstream>
#include <iostream>

void loadBMP(const std::string& filename, BMPHeader& bmpHeader, DIBHeader& dibHeader, std::vector<Pixel>& pixels) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening BMP file!" << std::endl;
        return;
    }

    // Function to load a BMP image
    // It reads the headers (BMP and DIB) and the pixel data into a vector of pixels.
    file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
    if (bmpHeader.signature[0] != 'B' || bmpHeader.signature[1] != 'M') {
        std::cerr << "Invalid BMP file format!" << std::endl;
        return;
    }

    // Read the BMP header
    file.read(reinterpret_cast<char*>(&dibHeader), sizeof(dibHeader));
    if (dibHeader.bpp != 24) {
        std::cerr << "Only 24-bit BMP images are supported!" << std::endl;
        return;
    }


    // Calculate the row size considering padding
    size_t rowSize = dibHeader.width * 3 + (4 - (dibHeader.width * 3) % 4) % 4;
    pixels.resize(dibHeader.width * dibHeader.height);
    // Move the file pointer to the start of the pixel data
    file.seekg(bmpHeader.dataOffset, std::ios::beg);
    // Read pixel data, starting from the bottom row (BMP stores pixels bottom to top)
    for (int y = dibHeader.height - 1; y >= 0; --y) {
        file.read(reinterpret_cast<char*>(&pixels[y * dibHeader.width]), dibHeader.width * 3);
        file.seekg(rowSize - dibHeader.width * 3, std::ios::cur); // Паддинг
    }
}

// Function to save a BMP image
// It writes the headers and pixel data to a file.
void saveBMP(const std::string& filename, const BMPHeader& bmpHeader, const DIBHeader& dibHeader, const std::vector<Pixel>& pixels) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening BMP file for writing!" << std::endl;
        return;
    }


    file.write(reinterpret_cast<const char*>(&bmpHeader), sizeof(bmpHeader));
    file.write(reinterpret_cast<const char*>(&dibHeader), sizeof(dibHeader));

    size_t rowSize = dibHeader.width * 3 + (4 - (dibHeader.width * 3) % 4) % 4;
    for (int y = dibHeader.height - 1; y >= 0; --y) {
        file.write(reinterpret_cast<const char*>(&pixels[y * dibHeader.width]), dibHeader.width * 3);
        uint8_t padding[3] = {0, 0, 0};
        file.write(reinterpret_cast<const char*>(&padding), rowSize - dibHeader.width * 3);
    }
}

