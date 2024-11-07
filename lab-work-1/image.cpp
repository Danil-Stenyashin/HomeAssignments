#include "Image.h"

#include <fstream>
#include <vector>

Image::Image(const string& filename) {
  ifstream file;
  file.open(filename, ios::binary | ios::in);
  if (!file.is_open()) {
    throw runtime_error("Не удалось открыть файл изображения");
  }

  // Пропускаем заголовок файла BMP
  file.seekg(54);

  // Считываем ширину и высоту изображения
  file.read((char*)&width_, sizeof(width_));
  file.read((char*)&height_, sizeof(height_));

  // Вычисляем размер памяти для хранения изображения
  memory_size_ = width_ * height_ * 3;

  // Считываем данные изображения
  data_.resize(height_);
  for (int i = 0; i < height_; ++i) {
    data_[i].resize(width_);
    file.read((char*)&data_[i][0], width_ * 3);
  }

  file.close();
}

Image::Image(const Image& other) {
  width_ = other.width_;
  height_ = other.height_;
  memory_size_ = other.memory_size_;
  data_ = other.data_;
}

void Image::save(const string& filename) const {
  ofstream file;
  file.open(filename, ios::binary | ios::out);
  if (!file.is_open()) {
    throw runtime_error("Не удалось открыть файл для записи");
  }

  // Записываем заголовок файла BMP
  file << "BM";
  file << (char)0;
  file << (char)0;
  file << (char)0;
  file << (char)0;
  int offset = 54;
  file.write((char*)&offset, sizeof(offset));
  int dib_header_size = 40;
  file.write((char*)&dib_header_size, sizeof(dib_header_size));
  file.write((char*)&width_, sizeof(width_));
  file.write((char*)&height_, sizeof(height_));
  int planes = 1;
  file.write((char*)&planes, sizeof(planes));
  int bits_per_pixel = 24;
  file.write((char*)&bits_per_pixel, sizeof(bits_per_pixel));
  int compression = 0;
  file.write((char*)&compression, sizeof(compression));
  int image_size = width_ * height_ * 3;
  file.write((char*)&image_size, sizeof(image_size));
  int x_ppm = 0;
  file.write((char*)&x_ppm, sizeof(x_ppm));
  int y_ppm = 0;
  file.write((char*)&y_ppm, sizeof(y_ppm));
  int colors_used = 0;
  file.write((char*)&colors_used, sizeof(colors_used));
  int important_colors = 0;
  file.write((char*)&important_colors, sizeof(important_colors));

  // Записываем данные изображения
  for (int i = 0; i < height_; ++i) {
    file.write((char*)&data_[i][0], width_ * 3);
  }

  file.close();
}

ostream& operator<<(ostream& os, const Image& image) {
  os << "Ширина: " << image.getWidth() << endl;
  os << "Высота: " << image.getHeight() << endl;
  os << "Размер памяти: " << image.getMemorySize() << " байт" << endl;
  return os;
}
