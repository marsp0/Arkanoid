#pragma once

#include "State.hpp"
#include "Button.hpp"

enum class ButtonPressed {
    NewGame = 0,
    Quit
};

class MenuState : public State {
public:
    MenuState();
    ~MenuState();

    void Update(sf::RenderWindow& l_window);
    void Render(sf::RenderWindow& l_window);
    void HandleInput(sf::RenderWindow& l_window);

    sf::Vector2i m_mousePosition;
    bool m_pressed;
    bool m_buttonPressed[2];

private:
    sf::RectangleShape m_background;
    Button m_buttonNewGame;
    Button m_buttonQuitGame;
    
};