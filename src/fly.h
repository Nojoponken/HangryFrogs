#ifndef FLY_H
#define FLY_H

#include "enemy.h"

/**
 * @brief Implementation of the abstract Enemy class.
 *
 */
class Fly : public Enemy
{
public:
    Fly(sf::Texture const &texture, sf::Vector2f const &coordinates, int const checkpoint, std::vector<sf::Vector2f> const &path);
    /**
     * @brief Moves the object along a path.
     *
     * @param delta Delta time to move the object in relation to.
     */
    void update(sf::Time const &delta) override;
};

#endif