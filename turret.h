#ifndef TURRET_H
#define TURRET_H

#include <cmath>
#include "object.h"

class Turret : public Object
{
private:
    void shoot();

public:
    Turret(sf::Texture &texture, sf::Vector2f coordinates);
    void update(sf::Time delta) override;
};

#endif // TURRET_H