/* Danil Stenyashin st128493@student.spbu.ru
Assigment2a_binary-open program / Checking the infile opening
*/

#ifndef CHECK_CPP
#define CHECK_CPP


// Функция для проверки открытия файла
bool check_file(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return false; // Возвращаем false, если файл не открылся
    }
    return true; // Возвращаем true, если файл открылся успешно
}

#endif
