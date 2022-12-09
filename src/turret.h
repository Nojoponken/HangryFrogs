#ifndef TURRET_H
#define TURRET_H

#include <cmath>

#include "entity.h"

class World;

class Turret : public Entity
{
private:
public:
    Turret(sf::Texture &texture, sf::Vector2f coordinates, int radius, int attack_radius);
    virtual ~Turret() = default;
    virtual void update(sf::Time delta) override;
    void set_position(sf::Vector2f coord);

protected:
    int attack_radius;
    virtual void attack(World &world, sf::Time delta) = 0;
};

#endif // TURRET_H