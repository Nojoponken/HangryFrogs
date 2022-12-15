#include "projectile.h"

Projectile::Projectile(sf::Texture const &texture, sf::Vector2f const &coordinates,
                       float const radius, sf::Vector2f const &velocity, std::vector<Entity *> &entities)
    : Entity(texture, coordinates, radius), entities{entities}
{
    direction = velocity;
    projectile_hit = false;
}

void Projectile::update(sf::Time const &delta)
{
    coordinates.x += direction.x * delta.asSeconds();
    coordinates.y += direction.y * delta.asSeconds();
    hit();
}

void Projectile::hit()
{
    for (Entity *entity : entities)
    {
        Enemy *enemy{dynamic_cast<Enemy *>(entity)};
        if (enemy)
        {
            if (collision(get_radius(), *enemy))
            {
                enemy->take_damage();
                projectile_hit = true;
            }
        }
    }
}

bool Projectile::get_projectile_hit() const
{
    return projectile_hit;
}