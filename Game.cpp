#include "Game.hpp"
#include <iostream>

Game::Game() : m_window(sf::VideoMode(800,600,32), "Arkanoid", sf::Style::Titlebar | sf::Style::Close ), m_game(), m_menu()
{
    m_clock.restart();
    m_elapsed = 0.0f;
    m_window.setFramerateLimit(60);
}

Game::~Game(){

}

void Game::HandleInput(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        m_window.close();
    }
    // Call State Handle Input here
    m_game.HandleInput();
}

void Game::Update() {
    // Call State Update Here 
    m_game.Update(*GetWindow());
    m_menu.Update(*GetWindow());
}

void Game::RestartClock(){
    m_elapsed += m_clock.restart().asSeconds();
}

void Game::Render(){
    m_window.clear(sf::Color(150,207,234));
    m_game.Render(*GetWindow());
    m_menu.Render(*GetWindow());
    m_window.display();
}

void Game::Run(){
    while (m_window.isOpen()) {
        // float timestep = 1.0f/60;
        float timestep = 1.f/60;
        HandleInput();
        while (m_elapsed >= timestep) {
            Update();
            m_elapsed -= timestep;
        }
        Render();
        RestartClock();
    }
}

sf::RenderWindow* Game::GetWindow() {
    return &m_window;
}