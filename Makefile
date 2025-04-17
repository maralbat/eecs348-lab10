CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

TARGET = calculator
SRC = main.cpp calculator.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o