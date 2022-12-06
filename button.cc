#include "button.h"

Button::Button(sf::Texture &texture, Turret *turret)
    : button_sprite{texture}, turret{turret}
{
    button_sprite.setTexture(texture);
}

void Button::draw_button(sf::RenderWindow &window)
{

    button_sprite.setScale(0.5, 0.5);
    window.draw(button_sprite);
}

void Button::set_position(sf::Vector2f coordinates)
{
    button_sprite.setPosition(coordinates.x, coordinates.y);
}

sf::Sprite &Button::get_sprite()
{
    return button_sprite;
}

void Button::set_turret_pos(sf::RenderWindow &window)
{
    turret->set_position(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}

Turret *Button::get_turret()
{
    return turret;
}