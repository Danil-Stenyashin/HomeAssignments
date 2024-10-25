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
    BMPFileHeader fileHeader;
    file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    
    BMPFileHeader infoHeader;
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
    
    if (fileHeader.bfType != 0x4D42) {
        std::cerr << "Error: this file is not BMP!" << std::endl;
        return 1;
    }
    
   
    file.close();
    
    return 0;    
}
