#include "turret.h"

Turret::Turret(sf::Texture &texture, sf::Vector2f coordinates, int radius, int attack_radius, std::vector<Entity *> &entities)
    : Entity(texture, coordinates, radius), attack_radius{attack_radius}, entities{entities}
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

void Turret::set_position(sf::Vector2f coord)
{
    coordinates = coord;
}
