CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror -Wpedantic
LDXXFLAGS = -lgtest -lgtest_main

SRC = MyClass.h Class_ftest.h
OBJ = $(SRC:.cpp=.o)
TEST_SRC = test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TARGET = test

.PHONY: default all clean cleanall

default: all

all: $(TARGET)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ) $(TEST_OBJ)
	$(CXX) -o $@ $(OBJ) $(TEST_OBJ) $(LDXXFLAGS)

test: $(TARGET)

clean:
	rm -f *.o

cleanall: clean
	rm -f $(TARGET)
