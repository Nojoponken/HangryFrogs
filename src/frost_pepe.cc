#include "frost_pepe.h"

Frost_Pepe::Frost_Pepe(sf::Texture &texture, sf::Vector2f position, std::vector<Entity *> &entities)
    : Turret(texture, position, 64, 128, entities)
{
}

void Frost_Pepe::attack(sf::Time delta)
{
    std::vector<Enemy *> enemies{};

    for (Entity *entity : entities)
    {
        Enemy *enemy{dynamic_cast<Enemy *>(entity)};
        if (enemy)
        {
            if (collision(attack_radius, *enemy))
            {
                enemy->set_slow(true);
            }
            else
            {
                enemy->set_slow(false);
            }
        }
    }
}

void Frost_Pepe::update(sf::Time delta)
{
    float current_angle{6.24f * delta.asSeconds()};

    sf::Vector2f new_direction{0, 0};
    new_direction.x = direction.x * std::cos(current_angle) -
                      direction.y * std::sin(current_angle);

    new_direction.y = direction.x * std::sin(current_angle) +
                      direction.y * std::cos(current_angle);

    direction = new_direction;
    attack(delta);
}
