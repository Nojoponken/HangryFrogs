#include "mcfly.h"

McFly::McFly(sf::Texture &texture, sf::Vector2f coordinates, std::vector<sf::Vector2f> const &path, std::vector<Entity *> &entities, sf::Texture &spawned_texture)
    : Enemy(texture, coordinates, 64, 5, 0, path, 15), entities{entities}, spawned_texture{spawned_texture}
{
}

void McFly::update(sf::Time delta)
{
    Enemy::point_to_path(delta);
    cooldown -= delta.asSeconds();

    if (cooldown <= 0)
    {
        cooldown = 3;
        entities.push_back(new Fly{spawned_texture, coordinates, get_checkpoint(), path});
    }
}