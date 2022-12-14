#ifndef FLY_H
#define FLY_H

#include "enemy.h"

class Fly : public Enemy
{
public:
    Fly(sf::Texture &texture, sf::Vector2f coordinates, int checkpoint, std::vector<sf::Vector2f> const &path);
    void update(sf::Time delta) override;
};

#endif