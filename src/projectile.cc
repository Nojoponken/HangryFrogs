#include "projectile.h"

Projectile::Projectile(sf::Texture &texture, sf::Vector2f coordinates,
                       float radius, sf::Vector2f velocity, std::vector<Entity *> &entities)
    : Entity(texture, coordinates, radius), entities{entities}
{
    direction = velocity;
    projectile_hit = false;
}

void Projectile::update(sf::Time delta)
{
    coordinates.x += direction.x;
    coordinates.y += direction.y;
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