CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = main

SRCS = greet.cpp main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) 
 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
