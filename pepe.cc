#include "pepe.h"

Pepe::Pepe(sf::Texture &texture, sf::Vector2f position, float radius)
    : Turret(texture, position, radius)
{
}

void Pepe::update(sf::Time delta)
{
    Turret::update(delta);
}