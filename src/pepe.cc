#include "pepe.h"

Pepe::Pepe(sf::Texture &texture, sf::Vector2f position, std::vector<Entity *> &entities)
    : Turret(texture, position, 64, 80, entities), cooldown{0}
{
}

void Pepe::attack(sf::Time delta)
{

    /*
     for (Enemy *enemy : enemies)
     {
         if (collision(attack_radius, *enemy))
         {
             std::cout << "Före : " << enemy->get_health() << std::endl;
             enemy->take_damage();
             std::cout << "Efter : " << enemy->get_health() << std::endl;
         }
     }

     std::vector<Enemy *> enemies{}; */
    if (cooldown <= 0)
    {
        for (Entity *entity : entities)
        {
            Enemy *enemy{dynamic_cast<Enemy *>(entity)};
            if (enemy)
            {
                if (collision(attack_radius, *enemy))
                {
                    std::cout << "Före : " << enemy->get_health() << std::endl;
                    enemy->take_damage();
                    std::cout << "Efter : " << enemy->get_health() << std::endl;
                                }
            }
        }
        cooldown = 1;
    }
    else
    {
        cooldown -= delta.asSeconds();
    }
}

void Pepe::update(sf::Time delta)
{
    Turret::update(delta);
    attack(delta);
}
