#ifndef PEPE_H
#define PEPE_H

#include "turret.h"
#include "world.h"

class Pepe : public Turret
{
private:
    void attack(World &world, sf::Time delta) override;

public:
    Pepe(sf::Texture &texture, sf::Vector2f position);

    void update(sf::Time delta) override;
};

#endif