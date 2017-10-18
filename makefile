output: main.o Game.o Ball.o Paddle.o GameState.o Button.o MenuState.o
	g++ -std=c++14 main.o Game.o Ball.o Paddle.o GameState.o Button.o MenuState.o -o output -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -std=c++14 -c main.cpp 

Game.o: Game.cpp Game.hpp
	g++ -std=c++14 -c Game.cpp 

Ball.o: Ball.cpp Ball.hpp
	g++ -std=c++14 -c Ball.cpp 

Paddle.o: Paddle.cpp Paddle.hpp
	g++ -std=c++14 -c Paddle.cpp 

GameState.o: GameState.cpp GameState.hpp
	g++ -std=c++14 -c GameState.cpp 

Button.o: Button.cpp Button.hpp
	g++ -std=c++14 -c Button.cpp 

MenuState.o: MenuState.cpp MenuState.hpp
	g++ -std=c++14 -c MenuState.cpp 

clean:
	rm *.o output