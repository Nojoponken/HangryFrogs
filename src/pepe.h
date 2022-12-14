#ifndef PEPE_H
#define PEPE_H

#include "turret.h"
#include "projectile.h"
#include "enemy.h"

class Pepe : public Turret
{
private:
    void attack(sf::Time delta) override;
    float cooldown;
    sf::Texture &projectile_texture;

public:
    Pepe(sf::Texture &texture, sf::Vector2f position,
         std::vector<Entity *> &entities,
         sf::Texture &projectile_texture);
    void update(sf::Time delta) override;
};

#endif