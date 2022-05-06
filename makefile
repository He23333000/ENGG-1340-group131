game_module.o game_module.cpp test.h
        g++ -c game_module.cpp

main.o main.cpp test.h
        g++ -c main.cpp
    
program: main.o game_module.o
