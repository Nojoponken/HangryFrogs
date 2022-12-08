#include "pepe.h"

Pepe::Pepe(sf::Texture &texture, sf::Vector2f position)
    : Turret(texture, position, 64, 256)
{
}

void Pepe::attack(World &world, sf::Time delta)
{
}

void Pepe::update(sf::Time delta)
{
    Turret::update(delta);
}
