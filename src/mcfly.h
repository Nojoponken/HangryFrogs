#ifndef MCFLY_H
#define MCFLY_H

#include "enemy.h"
#include "fly.h"

class McFly : public Enemy
{
private:
    std::vector<Entity *> &entities;
    float cooldown;
    sf::Texture &spawned_texture;

public:
    McFly(sf::Texture &texture, sf::Vector2f coordinates,
          std::vector<sf::Vector2f> const &path,
          std::vector<Entity *> &entities, sf::Texture &spawned_texture);

    void update(sf::Time delta) override;
};

#endif