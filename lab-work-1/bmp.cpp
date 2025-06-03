#include "bmp.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <mutex>

BMPImage::BMPImage(const std::string& filename, bool parallel) {
    if (parallel) {
        loadBMP_parallel(filename);
    } else {
        loadBMP_sequential(filename);
    }
}

void BMPImage::loadBMP_sequential(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening BMP file!" << std::endl;
        return;
    }

    file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
    if (bmpHeader.signature[0] != 'B' || bmpHeader.signature[1] != 'M') {
        std::cerr << "Invalid BMP file format!" << std::endl;
        return;
    }

    file.read(reinterpret_cast<char*>(&dibHeader), sizeof(dibHeader));
    if (dibHeader.bpp != 24) {
        std::cerr << "Only 24-bit BMP images are supported!" << std::endl;
        return;
    }

    pixels.resize(dibHeader.width * dibHeader.height);
    size_t rowSize = dibHeader.width * 3 + (4 - (dibHeader.width * 3) % 4) % 4;

    file.seekg(bmpHeader.dataOffset, std::ios::beg);
    for (int y = dibHeader.height - 1; y >= 0; --y) {
        for (int x = 0; x < dibHeader.width; ++x) {
            Pixel p;
            file.read(reinterpret_cast<char*>(&p.blue), sizeof(uint8_t));
            file.read(reinterpret_cast<char*>(&p.green), sizeof(uint8_t));
            file.read(reinterpret_cast<char*>(&p.red), sizeof(uint8_t));
            pixels[y * dibHeader.width + x] = p;
        }
        file.seekg(rowSize - dibHeader.width * 3, std::ios::cur);
    }
}
void BMPImage::loadBMP_parallel(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Error opening BMP file!" << std::endl;
        return;
    }
    size_t fileSize = file.tellg();
    file.seekg(0);

    file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
    if (bmpHeader.signature[0] != 'B' || bmpHeader.signature[1] != 'M') {
        std::cerr << "Invalid BMP file format!" << std::endl;
        return;
    }

    file.read(reinterpret_cast<char*>(&dibHeader), sizeof(dibHeader));
    if (dibHeader.bpp != 24) {
        std::cerr << "Only 24-bit BMP images are supported!" << std::endl;
        return;
    }

    std::vector<char> fileBuffer(fileSize);
    file.seekg(0);
    file.read(fileBuffer.data(), fileSize);
    file.close();

    pixels.resize(dibHeader.width * dibHeader.height);
    const size_t rowSize = dibHeader.width * 3 + (4 - (dibHeader.width * 3) % 4) % 4;
    const int num_threads = std::max(1, (int)std::thread::hardware_concurrency());
    const int rows_per_thread = (dibHeader.height + num_threads - 1) / num_threads;
    
    std::vector<std::thread> threads;

    auto process_rows = [&](int start_row, int end_row) {
        const char* fileData = fileBuffer.data() + bmpHeader.dataOffset;
        for (int y = start_row; y < end_row; ++y) {
            const int actual_y = dibHeader.height - 1 - y;
            const char* rowStart = fileData + actual_y * rowSize;
            
            for (int x = 0; x < dibHeader.width; ++x) {
                pixels[actual_y * dibHeader.width + x] = {
                    static_cast<uint8_t>(rowStart[x*3]),
                    static_cast<uint8_t>(rowStart[x*3+1]),
                    static_cast<uint8_t>(rowStart[x*3+2])
                };
            }
        }
    };
    
    for (int i = 0; i < num_threads; ++i) {
        const int start_row = i * rows_per_thread;
        const int end_row = std::min(start_row + rows_per_thread, dibHeader.height);
        threads.emplace_back(process_rows, start_row, end_row);
    }
    
    for (auto& t : threads) {
        t.join();
    }
}
void BMPImage::saveBMP(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error creating BMP file!" << std::endl;
        return;
    }

    uint32_t rowSize = dibHeader.width * 3 + (4 - (dibHeader.width * 3) % 4) % 4;
    
    BMPHeader outHeader = bmpHeader;
    DIBHeader outDibHeader = dibHeader;
    
    outHeader.fileSize = sizeof(BMPHeader) + sizeof(DIBHeader) + rowSize * dibHeader.height;
    outDibHeader.imageSize = rowSize * dibHeader.height;

    file.write(reinterpret_cast<const char*>(&outHeader), sizeof(outHeader));
    file.write(reinterpret_cast<const char*>(&outDibHeader), sizeof(outDibHeader));

    std::vector<char> rowBuffer(rowSize, 0);
    for (int y = dibHeader.height - 1; y >= 0; --y) {
        for (int x = 0; x < dibHeader.width; ++x) {
            const Pixel& p = pixels[y * dibHeader.width + x];
            rowBuffer[x*3] = p.blue;
            rowBuffer[x*3 + 1] = p.green;
            rowBuffer[x*3 + 2] = p.red;
        }
        file.write(rowBuffer.data(), rowSize);
    }
}

const std::vector<Pixel>& BMPImage::getPixels() const { return pixels; }
void BMPImage::setPixels(const std::vector<Pixel>& newPixels) { pixels = newPixels; }
const DIBHeader& BMPImage::getDIBHeader() const { return dibHeader; }
const BMPHeader& BMPImage::getBMPHeader() const { return bmpHeader; }
