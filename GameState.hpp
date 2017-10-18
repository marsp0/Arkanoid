#pragma once

#include "State.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"

class GameState : public State {
public:
    GameState();
    ~GameState();

    void Update(sf::RenderWindow& l_window);
    void Render(sf::RenderWindow& l_window);
    void HandleInput();
private:
    Ball m_ball;
    Paddle m_paddle;
    std::vector<sf::RectangleShape> m_bricks;
};