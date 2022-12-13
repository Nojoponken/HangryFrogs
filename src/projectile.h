#ifndef PROJECT_H
#define PROJECT_H

#include "entity.h"

class Projectile : public Entity
{
private:
public:
    Projectile(sf::Texture &texture, sf::Vector2f coordinates, float radius, sf::Vector2f velocity);
    void update(sf::Time delta) override;
};

#endif