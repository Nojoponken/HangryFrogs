#include "fly.h"

Fly::Fly(sf::Texture const &texture, sf::Vector2f const &coordinates,
         int const checkpoint, std::vector<sf::Vector2f> const &path)
    : Enemy(texture, coordinates, 32, 1, checkpoint, path, 50)
{
}

void Fly::update(sf::Time const &delta)
{
    Enemy::point_to_path(delta);
}