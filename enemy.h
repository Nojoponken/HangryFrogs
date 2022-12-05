#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include <cmath>
class Enemy : public Entity
{
private:
    int health;
    int checkpoint;
    std::vector<sf::Vector2f> const &path;

public:
    Enemy(sf::Texture &texture, sf::Vector2f coordinates, float radius, int health, std::vector<sf::Vector2f> const &path);
    virtual void update(sf::Time delta) override;
};

#endif
