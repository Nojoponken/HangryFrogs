#ifndef FROST_PEPE_H
#define FROST_PEPE_H

#include "turret.h"
class Frost_Pepe : public Turret
{
private:
    virtual void attack(sf::Time delta);

public:
    Frost_Pepe(sf::Texture &texture, sf::Vector2f position, std::vector<Entity *> &entities);
    void update(sf::Time delta) override;
};

#endif
