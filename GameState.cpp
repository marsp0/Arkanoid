#include <SFML/Graphics.hpp>
#include "GameState.hpp"

GameState::GameState():  m_ball(), m_paddle() {
    Restart();
}

GameState::~GameState(){

}

void GameState::Update(sf::RenderWindow& l_window){
    m_ball.Update(m_paddle);
    if (m_ball.m_gameOver) {
        Restart();
        m_ball.m_gameOver = false;
    }
    m_paddle.Update();
    for (int i=0; i < m_bricks.size() ; i++) {
        sf::FloatRect brick = m_bricks[i].getGlobalBounds();
        bool remove_brick = m_ball.Update(brick);
        if (remove_brick) {
            m_bricks.erase(m_bricks.begin()+i);
        }
    }
}

void GameState::Render(sf::RenderWindow& l_window){
    l_window.draw(m_ball);
    l_window.draw(m_paddle);
    for (int i=0; i < m_bricks.size(); i++) {
        l_window.draw(m_bricks[i]);
    }
}

void GameState::HandleInput(sf::RenderWindow& l_window) {
}

void GameState::Restart(){
    m_ball.Restart();
    m_paddle.Restart();
    for (int i=0; i < 5 ; i++) {
        for (int j=0; j < 10; j++) {
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(60,35));
            rect.setPosition(j*65.f + 75 ,i*40.f + 50);
            rect.setFillColor(sf::Color(44, 176, 55));
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(1.5f);
            m_bricks.push_back(rect);
        }
    }
}