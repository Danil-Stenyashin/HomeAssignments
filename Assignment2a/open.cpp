/* Danil Stenyashin st128493@student.spbu.ru
Assigment2a_binary-open program / Opening and closing file
*/

#ifndef OPEN_CPP
#define OPEN_CPP

 
#include "size.cpp"
#include "check.cpp"

int open_file() {
    // Имя входного файла
    const char* input_filename = "source.pdf";
    
    // Имя выходного файла
    const char* output_filename = "temppdf.bin";

    // Открываем входной файл в бинарном режиме для чтения
    std::ifstream infile;
    infile.open("source.pdf", std::ios::binary|std::ios::in);
    

    // Проверяем, успешно ли открылся файл
    check_file(input_filename);
    
    // Получаем размер файла
    long unsigned int file_size = get_file_size(input_filename);
   

    // Выделяем память под массив
    char* buffer = new char[file_size];

    // Читаем файл в массив
    infile.read(buffer, file_size);

    // Разворачиваем массив
    for (long unsigned int i = 0; i < file_size / 2; ++i) {
        std::swap(buffer[i], buffer[file_size - i - 1]);
    }

    // Открываем выходной файл в бинарном режиме для записи
    std::ofstream outfile(output_filename, std::ios::binary|std::ios::out);

    // Записываем массив в выходной файл
    outfile.write(buffer, file_size);

    // Закрываем файлы
    infile.close();
    outfile.close();

    // Освобождаем память
    delete[] buffer;

    std::cout << "Файл успешно обработан!" << std::endl;

    return 0;
}

#endif


