#include "button.h"

Button::Button(sf::Texture &texture, std::string const &name)
    : button_sprite{}, name{name}
{
    button_sprite.setTexture(texture);
    button_sprite.setScale(0.5, 0.5);
}

void Button::draw_button(sf::RenderWindow &window)
{
    window.draw(button_sprite);
}

void Button::set_position(sf::Vector2f coordinates)
{
    button_sprite.setPosition(coordinates.x, coordinates.y);
}

sf::Sprite Button::get_sprite() const
{
    return button_sprite;
}

std::string Button::get_name() const
{
    return name;
}