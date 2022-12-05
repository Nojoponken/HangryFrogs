#include "enemy.h"

Enemy::Enemy(sf::Texture &texture, sf::Vector2f coordinates, float radius, int health, std::vector<sf::Vector2f> const &path)
    : Entity(texture, coordinates, radius), health{health}, checkpoint{0}, path{path}
{
}

void Enemy::update(sf::Time delta)
{
    sf::Vector2f target{path.at(checkpoint)};
    float dx{target.x - coordinates.x};
    float dy{target.y - coordinates.y};
    float distance{std::sqrt(dx * dx + dy * dy)};

    if (distance < 10)
    {
        checkpoint++;
    }
    coordinates.x += (dx / distance) * delta.asSeconds() * 50;
    coordinates.y += (dy / distance) * delta.asSeconds() * 50;

    direction = {dx, dy};
}