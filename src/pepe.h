#ifndef PEPE_H
#define PEPE_H

#include "turret.h"
#include "enemy.h"

class Pepe : public Turret
{
private:
    void attack(sf::Time delta) override;
    float cooldown;

public:
    Pepe(sf::Texture &texture, sf::Vector2f position, std::vector<Entity *> &entities);

    void update(sf::Time delta) override;
};

#endif