#include "fly.h"

Fly::Fly(sf::Texture &texture, sf::Vector2f coordinates, int checkpoint, std::vector<sf::Vector2f> const &path)
    : Enemy(texture, coordinates, 32, 1, checkpoint, path, 50)
{
}

void Fly::update(sf::Time delta)
{
    Enemy::point_to_path(delta);
}