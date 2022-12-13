#include "pepe.h"

Pepe::Pepe(sf::Texture &texture, sf::Vector2f position,
           std::vector<Entity *> &entities,
           sf::Texture &projectile_texture)
    : Turret(texture, position, 64, 128, entities),
      cooldown{0},
      projectile_texture{projectile_texture}
{
}

void Pepe::attack(sf::Time delta)
{
    std::vector<Enemy *> enemies{};

    for (Entity *entity : entities)
    {
        Enemy *enemy{dynamic_cast<Enemy *>(entity)};
        if (enemy)
        {
            if (collision(attack_radius, *enemy))
            {
                enemies.push_back(enemy);
            }
        }
    }
    if (!enemies.empty())
    {
        sort(enemies.begin(), enemies.end(), [](Enemy *enemy_1, Enemy *enemy_2)
             { return enemy_1->get_distance_left() < enemy_2->get_distance_left(); });
        //

        direction = enemies.at(0)->get_coordinates() - get_coordinates();
        if (cooldown <= 0)
        {

            float length{std::sqrt(direction.x * direction.x + direction.y * direction.y)};

            direction.x /= length * 10;
            direction.y /= length * 10;

            entities.push_back(new Projectile{
                projectile_texture,
                coordinates,
                16, direction});
            /* enemies.at(0)->take_damage(); */

            cooldown = 5;
        }
        else
        {
            cooldown -= delta.asSeconds();
        }
    }
    //
}

void Pepe::update(sf::Time delta)
{

    attack(delta);
}
