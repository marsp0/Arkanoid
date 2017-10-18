#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <iostream>

Button::Button(std::string l_title,sf::Vector2f l_position, sf::Color l_color, sf::Vector2f l_size){
    m_font.loadFromFile("zorque.ttf");
    m_text.setFont(m_font);
    m_text.setColor(sf::Color::Black);
    m_text.setString(l_title);
    m_text.setPosition(l_position.x+(l_size.x - m_text.getLocalBounds().width)/2 , l_position.y + l_size.y/2 - m_text.getLocalBounds().height);
    m_background.setSize(l_size);
    m_background.setPosition(l_position);
    m_background.setFillColor(l_color);
    m_normalColor = l_color;
    m_hoverColor = sf::Color(150,207,234);
    m_background.setOutlineColor(sf::Color::Black);
    m_background.setOutlineThickness(2.f);
}

Button::~Button() {

}

void Button::Update(sf::RenderWindow& l_window){

    if (m_background.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(l_window)))) {
        if (m_background.getFillColor() != m_hoverColor) {
            m_background.setFillColor(m_hoverColor);
        }
    } else {
        if (m_background.getFillColor() != m_normalColor) {
            m_background.setFillColor(m_normalColor);
        }
    }
}

void Button::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_background);
    l_window.draw(m_text);
}