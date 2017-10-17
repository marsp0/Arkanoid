#include "Game.hpp"
#include <iostream>

Game::Game() : m_window(sf::VideoMode(800,600,32), "Arkanoid", sf::Style::Titlebar | sf::Style::Close ), m_ball(), m_paddle()
{
    m_clock.restart();
    m_elapsed = 0.0f;
    m_window.setFramerateLimit(60);
    for (int i=0; i < 5 ; i++) {
        for (int j=0; j < 10; j++) {
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(60,35));
            rect.setPosition(j*65.f + 75 ,i*40.f + 50);
            rect.setFillColor(sf::Color::Blue);
            m_bricks.push_back(rect);
        }
    }
}

Game::~Game(){

}

void Game::HandleInput(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        m_window.close();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        std::cout << "321" << std::endl;
    }
}

void Game::Update() {
    m_ball.Update(m_paddle);
    m_paddle.Update();
    for (int i=0; i < m_bricks.size() ; i++) {
        sf::FloatRect brick = m_bricks[i].getGlobalBounds();
        bool remove_brick = m_ball.Update(brick);
        if (remove_brick) {
            m_bricks.erase(m_bricks.begin()+i);
        }
    }
}

void Game::RestartClock(){
    m_elapsed += m_clock.restart().asSeconds();
}

void Game::Render(){
    m_window.clear(sf::Color::White);
    m_window.draw(m_ball);
    m_window.draw(m_paddle);
    for (int i=0; i < m_bricks.size(); i++) {
        m_window.draw(m_bricks[i]);
    }
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
