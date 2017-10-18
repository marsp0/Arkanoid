#include <SFML/Graphics.hpp>
#include "MenuState.hpp"

MenuState::MenuState():  m_buttonNewGame("New Game", sf::Vector2f(205,155), sf::Color::White, sf::Vector2f(180,130)),
                        m_buttonSaveGame("Save Game", sf::Vector2f(415,155), sf::Color::White, sf::Vector2f(180,130)),
                        m_buttonOptions("Options", sf::Vector2f(205,315), sf::Color::White, sf::Vector2f(180,130)),
                        m_buttonQuitGame("Quit Game", sf::Vector2f(415,315), sf::Color::White, sf::Vector2f(180,130))
{
    m_background.setFillColor(sf::Color(44, 176, 55));
    m_background.setSize(sf::Vector2f(450.f,350.f));
    m_background.setPosition(175,125);
    m_background.setOutlineColor(sf::Color::Black);
    m_background.setOutlineThickness(2.f);
}

MenuState::~MenuState() {

}

void MenuState::Update(sf::RenderWindow& l_window) {
    m_buttonNewGame.Update(l_window);
    m_buttonOptions.Update(l_window);
    m_buttonQuitGame.Update(l_window);
    m_buttonSaveGame.Update(l_window);
}

void MenuState::Render(sf::RenderWindow& l_window){
    l_window.draw(m_background);
    m_buttonNewGame.Render(l_window);
    m_buttonSaveGame.Render(l_window);
    m_buttonOptions.Render(l_window);
    m_buttonQuitGame.Render(l_window);
}

void MenuState::HandleInput(){

}