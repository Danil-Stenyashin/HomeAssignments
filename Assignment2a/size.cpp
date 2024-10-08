/* Danil Stenyashin st128493@student.spbu.ru
Assigment2a_binary-open program / Getting the size
*/

#ifndef SIZE_CPP
#define SIZE_CPP

#include "check.cpp"

// Функция для получения размера файла
long unsigned int get_file_size(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    check_file(filename);
    file.seekg(0, std::ios::end);
    long unsigned int file_size = file.tellg();
    file.close();
    return file_size;
}

#endif
