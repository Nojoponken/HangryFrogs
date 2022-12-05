#include "turret.h"

Turret::Turret(sf::Texture &texture, sf::Vector2f coordinates, float radius)
    : Entity(texture, coordinates, radius)
{
}

void Turret::shoot()
{
}

void Turret::update(sf::Time delta)
{

    float current_angle{6.24f * delta.asSeconds()};

    sf::Vector2f new_direction{0, 0};
    new_direction.x = direction.x * std::cos(current_angle) -
                      direction.y * std::sin(current_angle);

    new_direction.y = direction.x * std::sin(current_angle) +
                      direction.y * std::cos(current_angle);

    direction = new_direction;
}