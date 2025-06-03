#ifndef BMP_H
#define BMP_H

#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>

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

struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

class BMPImage {
public:
    BMPImage(const std::string& filename, bool parallel = false);
    
    const BMPHeader& getBMPHeader() const;
    const DIBHeader& getDIBHeader() const;
    const std::vector<Pixel>& getPixels() const;
    void setPixels(const std::vector<Pixel>& newPixels);
    
    void saveBMP(const std::string& filename) const;

private:
    void loadBMP_sequential(const std::string& filename);
    void loadBMP_parallel(const std::string& filename);
    
    mutable std::mutex file_mutex;
    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    std::vector<Pixel> pixels;
};

#endif // BMP_H

