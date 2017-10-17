#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Paddle.hpp"
#include <iostream>

Ball::Ball(float radius, std::size_t pointCircle) : sf::CircleShape(radius, pointCircle) {
    
    m_ballVelocity = 6.0f;
    m_velocity = {-m_ballVelocity, -m_ballVelocity};
    sf::CircleShape::setPosition(400.f,400.f);
    sf::CircleShape::setRadius(10.f);
    sf::CircleShape::setOrigin(10.f,10.f);
    sf::CircleShape::setFillColor(sf::Color::Green);
}

Ball::~Ball() {

}

void Ball::Update(Paddle &l_paddle) {
    sf::CircleShape::move(m_velocity);
    if (l_paddle.right() >= left() and l_paddle.left() <= right() and l_paddle.bottom() >= top() and l_paddle.top() <= bottom()) {
        m_velocity.y = -m_ballVelocity;
        if (x() < l_paddle.x()){
            m_velocity.x = -m_ballVelocity;
        } else {
            m_velocity.x = m_ballVelocity;
        }
    } else {
        if (left() <= 0){
            m_velocity.x = m_ballVelocity;
        } else if (right() >= 800) {
            m_velocity.x = -m_ballVelocity;
        }

        if (top() <= 0) {
            m_velocity.y = m_ballVelocity;
        } else if (bottom() >= 600){
            m_velocity.y = -m_ballVelocity;
        }
    }
}

bool Ball::Update(sf::FloatRect &l_brick) {
    if (l_brick.left + l_brick.width >= left() and l_brick.left <= right() and 
        l_brick.top + l_brick.height >= top() and l_brick.top <= bottom()) {
        
        float overlapLeft = right() - l_brick.left;
        float overlapRight = l_brick.left+l_brick.width - left();
        float overlapTop = bottom() - l_brick.top;
        float overlapBottom = l_brick.top + l_brick.height - top();

        bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
        bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

        float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
        float minOverlapY{ballFromTop ? overlapTop : overlapBottom};

        if (abs(minOverlapX) < abs(minOverlapY)){
            m_velocity.x = ballFromLeft ? -m_ballVelocity : m_ballVelocity;
        } else {
            m_velocity.y = ballFromTop ? -m_ballVelocity : m_ballVelocity;
        }
        return true;
    } else {
        return false;
    }
}

float Ball::x() {
    return sf::CircleShape::getPosition().x;
}
float Ball::y() {
    return sf::CircleShape::getPosition().y;
}
float Ball::left() {
    return x() - sf::CircleShape::getRadius();
}
float Ball::right(){
    return x() + sf::CircleShape::getRadius();
}
float Ball::top() {
    return y() - sf::CircleShape::getRadius();
}
float Ball::bottom(){
    return y() + sf::CircleShape::getRadius();
}