#pragma once

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape {
public:
    Paddle();
    ~Paddle();
    void Update();
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();
private:
    sf::Vector2f m_velocity;
    float m_paddleVelocity;
};