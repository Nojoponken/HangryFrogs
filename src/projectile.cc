#include "projectile.h"

Projectile::Projectile(sf::Texture &texture, sf::Vector2f coordinates,
                       float radius, sf::Vector2f velocity)
    : Entity(texture, coordinates, radius)
{
    direction = velocity;
}

void Projectile::update(sf::Time delta)
{
    coordinates.x += direction.x;
    coordinates.y += direction.y;
}