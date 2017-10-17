output: main.o Game.o Ball.o Paddle.o
	g++ -std=c++14 main.o Game.o Ball.o Paddle.o -o output -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -std=c++14 -c main.cpp 

Game.o: Game.cpp Game.hpp
	g++ -std=c++14 -c Game.cpp 

Ball.o: Ball.cpp Ball.hpp
	g++ -std=c++14 -c Ball.cpp 

Paddle.o: Paddle.cpp Paddle.hpp
	g++ -std=c++14 -c Paddle.cpp 

clean:
	rm *.o output