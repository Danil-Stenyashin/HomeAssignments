# Переменные
CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall -std=c++17  # Убедитесь, что используете стандарт C++17 или выше
SRC = main.cpp Transformer.cpp OptimusPrime.cpp Bumblebee.cpp Megatron.cpp Weapon.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

# Добавим файлы для тестов
TEST_SRC = test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_EXEC = test_exec  # Уникальное имя для исполнимого файла тестов

# Правило по умолчанию
all: $(EXEC)

# Линкование исполнимого файла
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

# Линкование исполнимого файла для тестов
$(TEST_EXEC): $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(TEST_OBJ) -o $(TEST_EXEC) -lgtest -lgtest_main -pthread

# Компиляция исходных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка промежуточных файлов
clean:
	rm -f $(OBJ) $(EXEC) $(TEST_OBJ) $(TEST_EXEC)

# Прочие полезные команды
run: $(EXEC)
	./$(EXEC)

# Команда для запуска тестов
run_tests: $(TEST_EXEC)
	./$(TEST_EXEC)

# Форматирование исходников
format:
	astyle --style=allman *.cpp *.h

