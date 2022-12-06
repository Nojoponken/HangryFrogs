#ifndef TURRET_H
#define TURRET_H

#include <cmath>

#include "entity.h"

class Turret : public Entity
{
private:
    void shoot();

public:
    Turret(sf::Texture &texture, sf::Vector2f coordinates, float radius);
    virtual void update(sf::Time delta) override;
    void set_position(sf::Vector2f coord);
};

#endif // TURRET_H