#ifndef OPEN_H
#define OPEN_H

struct BMPFileHead {
     unsigned short bfType; // BM Type
     unsigned int bfSize; // Size of the file in bytes
     unsigned short bfReserved1;
     unsigned short bfReserved2;
     unsigned int bfOffBits; // 
};

struct BMPInfoHead {
    unsigned int biSize; // Size of the sctruct
    int biWidth; // Width of the file
    int biHeight; // Heigth of the file
    unsigned short biPlanes; // How many x,y,z (Anytime 1)
    unsigned short biBitCount; // Count of the bit (1, 4, 8, 16, 24, 32)
    unsigned biCompression; // Type of the compression
    unsigned int biSizeImage; // Size of the image in bytes
    int biXPelsPerMeter; // oX Pels Per Meter 
    int biYPelsPerMeter; // oY Pels Per Meter
    unsigned int biClrUsed; // Number of pixels
    unsigned int biClrImportant; // Number of inportant pixels
};

#endif
