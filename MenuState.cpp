#include <SFML/Graphics.hpp>
#include "MenuState.hpp"
#include <iostream>

MenuState::MenuState():  m_buttonNewGame("New Game", sf::Vector2f(300,140), sf::Color::White, sf::Vector2f(200,150)),
                        m_buttonQuitGame("Quit Game", sf::Vector2f(300,320), sf::Color::White, sf::Vector2f(200,150))
{
    m_background.setFillColor(sf::Color(44, 176, 55));
    m_background.setSize(sf::Vector2f(260.f,390.f));
    m_background.setPosition(270,110);
    m_background.setOutlineColor(sf::Color::Black);
    m_background.setOutlineThickness(2.f);
    for (int i=0; i < 3; i++){
        m_buttonPressed[i] = false;
    }
}

MenuState::~MenuState() {

}

void MenuState::Update(sf::RenderWindow& l_window) {
    m_buttonNewGame.Update(l_window);
    m_buttonQuitGame.Update(l_window);
}

void MenuState::Render(sf::RenderWindow& l_window){
    l_window.draw(m_background);
    m_buttonNewGame.Render(l_window);
    m_buttonQuitGame.Render(l_window);
}

void MenuState::HandleInput(sf::RenderWindow& l_window){
    if (m_pressed) {
        int temp;
        if (m_buttonNewGame.GetGlobalBounds().contains(sf::Vector2f(m_mousePosition))) {
            m_buttonPressed[0] = true;
            temp = 0;
        } else if (m_buttonQuitGame.GetGlobalBounds().contains(sf::Vector2f(m_mousePosition))) {
            m_buttonPressed[1] = true;
            temp = 1;
        }
        m_pressed = false;
        for (int i = 0; i < 2; i++) {
            if (i != temp) {
                m_buttonPressed[i] = false;
            }
        }
    }
}