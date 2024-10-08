CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = main
TRASH = output.bin

SRCS = main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) 
 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(TRASH)

