#include "head.h"
#include "open.h"


int main() {
    // Load a file
    std::string fileName;
    std::cout << "Write filename: ";
    std::cin >> fileName;
    
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: file '" << fileName << "' cannot open!" << std::endl;
        return 1;
    }
    
    // Read a head
    BMPFileHead fileHead;
    BMPInfoHead infoHead;
    
    file.read(reinterpret_cast<char*>(&fileHead), sizeof(fileHead));
    file.read(reinterpret_cast<char*>(&infoHead), sizeof(infoHead));
   
    
    
    if (fileHead.bfType != 0x4D42) {
        std::cerr << "Error: this file is not BMP!" << std::endl;
        return 1;
    }
    
    if (infoHead.biBitCount == 24) {
        std::cerr << "Supports only 24-bit format!" << std::endl;
        return 1;
    } 
    
    // Create vector for pixels
    std::vector<std::vector<unsigned char>> pixels(infoHead.biHeight, std::vector<unsigned char>(infoHead.biWidth * 3));
    
    // Чтение пикселей в массив
    for (int y = 0; y < infoHeader.biHeight; ++y) {
        for (int x = 0; x < infoHeader.biWidth; ++x) {
            int index = y * infoHeader.biWidth * 3 + x * 3; 
            file.read(reinterpret_cast<char*>(&pixels[y][index]), 3);
        }
    }
    
    file.seekg(fileHead.bfOffBits);
    
    std::cout << "Width: " << infoHead.biWidth << " pixels" << std::endl;
    std::cout << "Heigth: " << infoHead.biHeight << " pixels" << std::endl;
    std::cout << infoHead.biSize << std::endl;
    
    for (int y = 0; y < infoHead.biHeight; ++y) {
        for (int x = 0; x < infoHead.biWidth; ++x) {
            int index = y * infoHead.biWidth * 3 + x * 3; 
            std::cout << "Pixel (" << x << ", " << y << "): R=" << (int)pixels[y][index + 2] << ", G=" << (int)pixels[y][index + 1] << ", B=" << (int)pixels[y][index] << std::endl;
        }
    }
    
    file.close();
    
    return 0;    
}
