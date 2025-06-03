CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall -std=c++17 -pthread
SRC = main.cpp bmp.cpp image_processing.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = image_processor

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC) output_*.bmp

run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run
