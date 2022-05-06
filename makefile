game_module.o: game_module.cpp test.h
	g++ -pedantic-errors -std=c++11 -c game_module.cpp

main.o: main.cpp test.h
	g++ -pedantic-errors -std=c++11 -c main.cpp
    
program: main.o game_module.o
	g++ -pedantic-errors -std=c++11 main.o game_module.o -o program

.PHONY: clean

clean:
	rm -f game_module.o main.o 
