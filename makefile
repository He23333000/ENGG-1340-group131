all: game_module.o main.o program

game_module.o: game_module.cpp test.h
	g++ -c game_module.cpp

main.o: main.cpp test.h
	g++ -c main.cpp
    
program: main.o game_module.o
	g++ main.o game_module.o -o program

.PHONY: clean

clean:
	rm -f game_module.o main.o 
