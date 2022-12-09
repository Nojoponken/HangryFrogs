#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "turret.h"

class Button
{
private:
    sf::Sprite button_sprite;
    Turret *turret;

public:
    Button(sf::Texture &texture, Turret *turret);
    ~Button();
    void draw_button(sf::RenderWindow &window);
    void set_position(sf::Vector2f coordinates);
    sf::Sprite &get_sprite();

    void set_turret_pos(sf::RenderWindow &window);
    Turret *get_turret();
};

#endif