#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>

#include "entity.h"
class Enemy : public Entity
{
private:
    int health;
    int checkpoint;
    std::vector<sf::Vector2f> const &path;

public:
    Enemy(sf::Texture &texture, sf::Vector2f coordinates, float radius, int health, std::vector<sf::Vector2f> const &path);
    virtual ~Enemy() = default;
    virtual void update(sf::Time delta) override;
    virtual void take_damage();
    int get_health() const;
    float get_distance_left();
};

#endif
