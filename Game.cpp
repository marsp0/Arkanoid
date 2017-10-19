#include "Game.hpp"
#include <iostream>

Game::Game() : m_window(sf::VideoMode(800,600,32), "Arkanoid", sf::Style::Titlebar | sf::Style::Close ), m_game(), m_menu()
{
    m_clock.restart();
    m_elapsed = 0.0f;
    m_window.setFramerateLimit(60);
    m_window.setKeyRepeatEnabled(false);
    currentState = &m_menu;
}

Game::~Game(){

}

void Game::HandleInput(){
    sf::Event event;
    while (m_window.pollEvent(event)){

        if (sf::Event::EventType::Closed == event.type){
            m_window.close();
        } else if (event.type == sf::Event::EventType::KeyPressed){
            if (event.key.code == sf::Keyboard::Key::Escape) {
                ChangeState();
            }
        } else if (event.type == sf::Event::EventType::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Button::Left) {
                if (currentState == &m_menu){
                    m_menu.m_pressed = true;
                    m_menu.m_mousePosition = sf::Mouse::getPosition(*GetWindow());
                }
            }
        }

    }
    // Call State Handle Input here
    currentState->HandleInput(*GetWindow());
}

void Game::Update() {
    // Call State Update Here 
    currentState->Update(*GetWindow());
    if (currentState == &m_menu) {
        if (m_menu.m_buttonPressed[static_cast<int>(ButtonPressed::NewGame)] == true) {
            RestartGame();
            ChangeState();
            m_menu.m_buttonPressed[0] = false;
        } else if (m_menu.m_buttonPressed[static_cast<int>(ButtonPressed::Quit)] == true) {
            m_window.close();
            ChangeState();
        }
    }
}

void Game::RestartClock(){
    m_elapsed += m_clock.restart().asSeconds();
}

void Game::Render(){
    m_window.clear(sf::Color(150,207,234));
    currentState->Render(*GetWindow());
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

void Game::RestartGame() {
    m_game.Restart();
}

void Game::ChangeState(){
    if (currentState == &m_game){
        currentState = &m_menu;
    } else {
        currentState = &m_game;
    }
}