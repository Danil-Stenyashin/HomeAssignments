
CXX = g++                   
CXXFLAGS = -std=c++14 -Wall -Werror -Wpedantic -I$(GTEST_DIR)/include -pthread 
TARGET = main         
TEST_TARGET = test           


SRCS = main.cpp Transformer.cpp OptimusPrime.cpp Bumblebee.cpp Megatron.cpp Weapon.cpp
TEST_SRCS = test.cpp Transformer.cpp Weapon.cpp Bumblebee.cpp OptimusPrime.cpp Megatron.cpp

OBJS = $(SRCS:.cpp=.o)        
TEST_OBJS = $(TEST_SRCS:.cpp=.o)  


GTEST_DIR = /path/to/gtest


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)


test: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -lgtest -lgtest_main -pthread -o $(TEST_TARGET)
	./$(TEST_TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


format:
	@echo "Formatting source files with astyle..."
	astyle --style=allman --indent=tab $(SRCS) $(TEST_SRCS)


clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

	
.PHONY: all test clean format

