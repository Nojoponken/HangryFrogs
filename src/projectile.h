#ifndef PROJECT_H
#define PROJECT_H

#include "entity.h"
#include "enemy.h"

class Projectile : public Entity
{
private:
    std::vector<Entity *> &entities;
    bool projectile_status;

public:
    Projectile(sf::Texture &texture, sf::Vector2f coordinates,
               float radius, sf::Vector2f velocity,
               std::vector<Entity *> &entities);
    void update(sf::Time delta) override;
    void hit();
    bool get_projectile_status() const;
};

#endif