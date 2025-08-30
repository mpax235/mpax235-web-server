CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

SRC := src/mpax235.cpp src/http/http_response.cpp

TARGET := mpax235

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)