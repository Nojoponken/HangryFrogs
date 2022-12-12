#ifndef TURRET_H
#define TURRET_H

#include <cmath>

#include "entity.h"
#include "enemy.h"

class World;

class Turret : public Entity
{
private:
public:
    Turret(sf::Texture &texture, sf::Vector2f coordinates, int radius, int attack_radius, std::vector<Entity *> &entities);
    virtual ~Turret() = default;
    virtual void update(sf::Time delta) override;
    void set_position(sf::Vector2f coord);
    virtual bool collision_turrets(int const rad, std::vector<Entity *> &entities);

protected:
    int attack_radius;
    virtual void attack(sf::Time delta) = 0;
    std::vector<Entity *> &entities;
};

#endif // TURRET_H