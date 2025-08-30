CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

SRC := src/*.cpp src/http/*.cpp src/info/*.cpp src/socket/*.cpp

TARGET := mpax235

all: $(TARGET)

$(TARGET): $(SRC)
	@$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	@rm -f $(TARGET)