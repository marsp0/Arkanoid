#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

Paddle::Paddle() : sf::RectangleShape() {
    m_paddleVelocity = 8.0f;
    m_velocity = {m_paddleVelocity,0};
    sf::RectangleShape::setPosition(350,575);
    sf::RectangleShape::setSize(sf::Vector2f(100,25));
    sf::RectangleShape::setOrigin(50,12.5f);
    sf::RectangleShape::setFillColor(sf::Color(175, 55, 44));
    sf::RectangleShape::setOutlineColor(sf::Color::Black);
    sf::RectangleShape::setOutlineThickness(2.f);
}

Paddle::~Paddle(){

}

void Paddle::Update() {
    sf::RectangleShape::move(m_velocity);
    if ((left() > 0) and (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))) {
        m_velocity.x = -m_paddleVelocity;
    } else if ((right() < 800) and (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))) {
        m_velocity.x = m_paddleVelocity;
    } else {
        m_velocity.x = 0;
    }
}
float Paddle::x(){
    return sf::RectangleShape::getPosition().x;
}
float Paddle::y(){
    return sf::RectangleShape::getPosition().y;
}
float Paddle::left(){
    return x() - sf::RectangleShape::getSize().x/2.f;
}
float Paddle::right() {
    return x() + sf::RectangleShape::getSize().x/2.f;
}
float Paddle::top() {
    return y() - sf::RectangleShape::getSize().y/2.f;
}
float Paddle::bottom(){
    return y() + sf::RectangleShape::getSize().y/2.f;
}

void Paddle::Restart(){
    sf::RectangleShape::setPosition(350,575);
}