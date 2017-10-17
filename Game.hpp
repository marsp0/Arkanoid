#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Paddle.hpp"

class Game {
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();
    void Run();
    void RestartClock();
private:
    sf::RenderWindow m_window;
    Ball m_ball;
    sf::Clock m_clock;
    double m_elapsed;
    Paddle m_paddle;
    std::vector<sf::RectangleShape> m_bricks;
};