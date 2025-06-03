# Техническая документация: Параллельная обработка BMP

## 1. Архитектура решения
```mermaid
graph TD
    A[BMP Загрузчик] --> B[Пул потоков]
    B --> C[Обработчик поворотов]
    B --> D[Фильтр Гаусса]
    C --> E[Сохранение BMP]
    D --> E

## 2. Reference
### 2.1 Основные функции

/**
 * Параллельный поворот изображения
 * @param width,height - размеры изображения
 * @param src - исходные пиксели
 * @param dst - выходные пиксели (pre-allocated)
 * @param num_threads - количество потоков (0=auto)
 * @param chunk_size - размер блока обработки (0=auto)
 */
void rotate90Clockwise(int width, int height, 
                      const std::vector<Pixel>& src,
                      std::vector<Pixel>& dst,
                      unsigned num_threads = 0,
                      int chunk_size = 0);
                      
## 2.2 Параметры по умолчанию
Параметр	Значение по умолчанию	               Диапазон
num_threads	std::thread::hardware_concurrency()	1-64
chunk_size	32 (строки/столбцы)	                16-256
kernel_size	5 (Гаусс)                       	3-31 (нечетные)


## 3. Требования к данным
### 3.1 Поддерживаемые форматы
Характеристика	Значение
Битность	24-bit RGB
Сжатие	BI_RGB (без сжатия)
Макс. размер	16384×16384 px
Порядок пикселей	BGR (стандарт BMP)

## 4. Руководство интеграции
### 4.1 Сборка проекта

# Рекомендуемые флаги компиляции
g++ -O3 -march=native -pthread -DUSE_PARALLEL=1 ...

### 4.2 Пример использования

#include "parallel_bmp.h"

int main() {
    BMPProcessor processor;
    
    // Загрузка с автоматическим определением потоков
    processor.load("input.bmp");
    
    // Поворот с явным указанием параметров
    processor.rotate(90, ROTATE_CW, 4); // 4 потока
    
    // Фильтрация с настройками по умолчанию
    processor.gaussian_blur(5, 1.0f);
    
    processor.save("output.bmp");
}

## 5. Оптимальные практики
### 5.1 Выбор параметров

# Псевдокод для подбора параметров
def optimal_threads(img_size):
    if img_size < 1_000_000: return 1
    elif img_size < 5_000_000: return 4
    else: return min(12, os.cpu_count() - 1)

## 5.2 Ограничения

    Потребление памяти:

        Доп. 20% от размера изображения

        Пиковое использование: 2.5× исходного размера

    Производительность:
    
    graph LR
A[Размер] --> B{<1MP?}
B -->|Да| C[Последовательная]
B -->|Нет| D[Параллельная]


## 6. Технические лимиты
Ресурс	          Ограничение
Макс. потоков	        64
Макс. размер ядра	31×31
Миним. изображение	16×16 px


## 7. Решение проблем
### 7.1 Частые ошибки

# Ошибка: Cannot create thread
export OMP_THREAD_LIMIT=12  # Лимит для OpenMP

# Ошибка: Memory allocation failed
ulimit -v 4000000  # 4GB лимит памяти

