# Makefile

# Переменные
CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall
SRC = main.cpp bmp.cpp image_processing.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

# Правило по умолчанию
all: $(EXEC)

# Линкование исполнимого файла
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

# Компиляция исходных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка промежуточных файлов
clean:
	rm -f $(OBJ) $(EXEC)

# Прочие полезные команды
run: $(EXEC)
	./$(EXEC)

format:
	astyle --style=allman *.cpp *.h

