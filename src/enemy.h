#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>

#include "entity.h"
class Enemy : public Entity
{
private:
    int health;
    int speed;
    bool slowed;
    int checkpoint;

public:
    Enemy(sf::Texture &texture, sf::Vector2f coordinates, float radius, int health, int checkpoint, std::vector<sf::Vector2f> const &path, int speed);
    virtual ~Enemy() = default;
    virtual void update(sf::Time delta) override = 0;
    void take_damage();
    int get_health() const;
    float get_distance_left();
    void set_slow(bool slow);
    void point_to_path(sf::Time delta);
    int get_checkpoint();

protected:
    std::vector<sf::Vector2f> const &path;
};

#endif
