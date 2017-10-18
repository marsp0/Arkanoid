#include <SFML/Graphics.hpp>

class Button {
public:
    // Color
    // Position
    // Size
    // Text
    // Change these
    Button(std::string l_title,sf::Vector2f l_position, sf::Color l_color, sf::Vector2f l_size);
    ~Button();
    void Update(sf::RenderWindow& l_window);
    void Render(sf::RenderWindow& l_window);
    sf::FloatRect GetGlobalBounds();
private:
    sf::Text m_text;
    sf::Font m_font;
    sf::Vector2f m_position;
    sf::RectangleShape m_background;
    sf::Color m_normalColor;
    sf::Color m_hoverColor;
};