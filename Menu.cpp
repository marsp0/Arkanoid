#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include <iostream>


Menu::Menu() : m_newGame(sf::String("New Game"), sf::Vector2f(200.0f,50.0f), sf::Color(31, 117, 254), sf::Vector2f(300.0f,350.0f)),
                m_closeGame(sf::String("Close Game"), sf::Vector2f(200.0f,50.0f), sf::Color(31, 117, 254), sf::Vector2f(300.0f,425.0f)) 
{

    //text options 
    m_font.loadFromFile("Arial.ttf");
    m_text.setFont(m_font);
    m_text.setColor(sf::Color::White);
    m_text.setString("Menu");
    m_text.setPosition(sf::Vector2f(400.0f - m_text.getCharacterSize()*1.5f ,300.0f));

    m_background.setSize(sf::Vector2f(250.0f,250.0f));
    m_background.setFillColor(sf::Color(135,206,250));
    m_background.setPosition(sf::Vector2f(275.0f,275.0f));

}

Menu::~Menu(){

}

ButtonState Menu::Update(sf::Vector2i l_mousePosition){
    
    if (m_newGame.getGlobalBounds().contains(sf::Vector2f(l_mousePosition))) {
        return ButtonState::NewGame;
    } else if (m_closeGame.getGlobalBounds().contains(sf::Vector2f(l_mousePosition))) {
        return ButtonState::CloseGame;
    } else {
        return ButtonState::None;
    }
}

void Menu::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_background);
    l_window.draw(m_text);
    m_newGame.Render(l_window);
    m_closeGame.Render(l_window);
}