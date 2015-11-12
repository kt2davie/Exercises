CXXFLAGS?=-std=c++11 -Wall -O2 -g

default: all

all: bin bin/game_of_life

bin:
	mkdir bin

bin/game_of_life: src/main.cpp src/Board.cpp src/GameOfLife.cpp
	$(CXX) src/*.cpp $(CXXFLAGS) -o bin/game_of_life

clean:
	rm -r bin

