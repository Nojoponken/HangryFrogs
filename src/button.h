#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "turret.h"

class Button
{
private:
    sf::Sprite button_sprite;
    std::string name;

public:
    Button(sf::Texture &texture, std::string const &name);
    ~Button() = default;
    void draw_button(sf::RenderWindow &window);
    void set_position(sf::Vector2f coordinates);
    sf::Sprite get_sprite() const;
    std::string get_name() const;
};

#endif