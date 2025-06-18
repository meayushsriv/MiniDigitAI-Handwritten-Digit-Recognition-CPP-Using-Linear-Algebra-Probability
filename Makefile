CXX = g++
CXXFLAGS = -std=c++17 -O2

SRC = src/main.cpp src/classifier.cpp src/utils.cpp
INC = -Isrc

all: mini

mini: $(SRC)
	$(CXX) $(CXXFLAGS) $(INC) -o mini $(SRC)

clean:
	rm -f mini
