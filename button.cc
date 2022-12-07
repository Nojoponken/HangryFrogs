#include "button.h"
template <typename T>
Button<T>::Button(sf::Texture &texture, Turret *turret)
    : button_sprite{texture}, turret{turret}
{
    button_sprite.setTexture(texture);
}

template <typename T>
Button<T>::~Button()
{
    delete turret;
}

template <typename T>
void Button<T>::draw_button(sf::RenderWindow &window)
{

    button_sprite.setScale(0.5, 0.5);
    window.draw(button_sprite);
}

template <typename T>
void Button<T>::set_position(sf::Vector2f coordinates)
{
    button_sprite.setPosition(coordinates.x, coordinates.y);
}

template <typename T>
sf::Sprite &Button<T>::get_sprite()
{
    return button_sprite;
}

template <typename T>
void Button<T>::set_turret_pos(sf::RenderWindow &window)
{
    turret->set_position(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}

template <typename T>
Turret *Button<T>::get_turret()
{
    return new T{turret};
}