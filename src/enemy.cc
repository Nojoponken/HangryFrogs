#include "enemy.h"

Enemy::Enemy(sf::Texture &texture, sf::Vector2f coordinates, float radius, int health, std::vector<sf::Vector2f> const &path)
    : Entity(texture, coordinates, radius), health{health}, checkpoint{0}, path{path}
{
}

void Enemy::update(sf::Time delta)
{
    sf::Vector2f target{path.at(checkpoint)};

    float dx{0};
    float dy{0};

    dx = target.x - coordinates.x;
    dy = target.y - coordinates.y;
    float distance{std::sqrt(dx * dx + dy * dy)};
    if (distance < 10)
    {
        checkpoint++;
        if (checkpoint >= path.size())
        {
            health = 0;
        };
    }
    else
    {

        coordinates.x += (dx / distance) * delta.asSeconds() * 50;
        coordinates.y += (dy / distance) * delta.asSeconds() * 50;

        direction = {dx, dy};
    }
}

void Enemy::take_damage()
{
    if (health > 0)
    {
        health -= 1;
    }
}

int Enemy::get_health() const
{
    return health;
}

float pythagoras(sf::Vector2f a, sf::Vector2f b)
{
    float x{a.x - b.x};
    float y{a.y - b.y};
    return sqrt((x * x) + (y * y));
}

float Enemy::get_distance_left()
{
    float total{0};

    for (size_t index = checkpoint; index < path.size() - 1; index++)
    {
        total += pythagoras(path.at(index), path.at(index + 1));
    }
    total += distance(path.at(checkpoint));

    return total;
}