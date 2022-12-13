#include "pepe.h"

Pepe::Pepe(sf::Texture &texture, sf::Vector2f position, std::vector<Entity *> &entities)
    : Turret(texture, position, 64, 128, entities), cooldown{0}
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
            enemies.at(0)->take_damage();

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
