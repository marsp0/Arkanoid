#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "MenuState.hpp"

class Game {
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();
    void Run();
    void RestartClock();
    sf::RenderWindow* GetWindow();
    void RestartGame();
    void ChangeState();
private:
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    double m_elapsed;
    GameState m_game;
    MenuState m_menu;
    State *currentState;
};