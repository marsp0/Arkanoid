#pragma once
#include <SFML/Graphics.hpp>

class State {
public:
    void virtual Update(sf::RenderWindow& l_window)=0;
    void virtual Render(sf::RenderWindow& l_window)=0;
    void virtual HandleInput(sf::RenderWindow& l_window)=0;
};