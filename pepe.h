#ifndef PEPE_H
#define PEPE_H

#include "turret.h"

class Pepe : public Turret
{
public:
    Pepe(sf::Texture &texture, sf::Vector2f position);

    void update(sf::Time delta) override;
};

#endif