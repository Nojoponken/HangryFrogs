#include "turret.h"

Turret::Turret(sf::Texture const &texture, sf::Vector2f const &coordinates, float const radius, float const attack_radius, std::vector<Entity *> &entities)
    : Entity(texture, coordinates, radius), attack_radius{attack_radius}, entities{entities}
{
}

void Turret::set_position(sf::Vector2f const &coord)
{
    coordinates = coord;
}

bool Turret::collision_turrets(int const rad) const
{
    for (Entity *entity : entities)
    {
        if (collision(rad, *entity))
        {
            return true;
        }
    }
    return false;
}