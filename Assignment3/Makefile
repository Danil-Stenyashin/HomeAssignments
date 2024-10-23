CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = main

SRCS = main.cpp Transformer.cpp OptimusPrime.cpp Bumblebee.cpp Megatron.cpp Weapon.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) 
 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
