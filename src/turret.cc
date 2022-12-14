#include "turret.h"

Turret::Turret(sf::Texture &texture, sf::Vector2f coordinates, float radius, float attack_radius, std::vector<Entity *> &entities)
    : Entity(texture, coordinates, radius), attack_radius{attack_radius}, entities{entities}
{
}

void Turret::set_position(sf::Vector2f coord)
{
    coordinates = coord;
}

bool Turret::collision_turrets(int const rad)
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