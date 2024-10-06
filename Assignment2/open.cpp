/* Danil Stenyashin st128493@student.spbu.ru
Assigment2a_binary-open programm
*/

#include <iostream>
#include <fstream>
using namespace std;

int open() {
    // Имя входного файла
    const char* input_filename = "input.bin";
    // Имя выходного файла
    const char* output_filename = "output.bin";

    // Открываем входной файл в бинарном режиме для чтения
    ifstream input_file(input_filename, ios::binary);

    // Проверяем, успешно ли открылся файл
    if (!input_file.is_open()) {
        std::cerr << "Ошибка открытия файла " << input_filename << std::endl;
        return 1;
    }

    // Получаем размер файла
    input_file.seekg(0, ios::end);
    size_t file_size = input_file.tellg();
    input_file.seekg(0, ios::beg);

    // Выделяем память под массив
    char* buffer = new char[file_size];

    // Читаем файл в массив
    input_file.read(buffer, file_size);

    // Разворачиваем массив
    for (size_t i = 0; i < file_size / 2; ++i) {
        swap(buffer[i], buffer[file_size - i - 1]);
    }

    // Открываем выходной файл в бинарном режиме для записи
    ofstream output_file(output_filename, ios::binary);

    // Записываем массив в выходной файл
    output_file.write(buffer, file_size);

    // Закрываем файлы
    input_file.close();
    output_file.close();

    // Освобождаем память
    delete[] buffer;

    std::cout << "Файл успешно обработан!" << std::endl;

    return 0;
}


