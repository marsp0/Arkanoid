#pragma once

#include "Paddle.hpp"
#include <SFML/Graphics.hpp>

class Ball: public sf::CircleShape {
public:
    Ball(float radius=0, std::size_t pointCount=30);
    ~Ball();
    void Update(Paddle &l_paddle);
    bool Update(sf::FloatRect &l_brick);
    float x();
    float y();
    float left();
    float right();
    float top();
    float bottom();
private:
    sf::Vector2f m_velocity;
    float m_ballVelocity;
};