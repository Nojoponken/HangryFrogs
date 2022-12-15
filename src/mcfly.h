#ifndef MCFLY_H
#define MCFLY_H

#include "enemy.h"
#include "fly.h"

/**
 * @brief Implementation of the  abstract Enemy class, can spawn Fly objects.
 *
 */
class McFly : public Enemy
{
private:
    std::vector<Entity *> &entities; /// Vector that spawned enemies are pushed to.
    float cooldown;                  /// Tracks the next time to spawn an enemy.
    sf::Texture &spawned_texture;    /// Texture of the spawned enemy.

public:
    McFly(sf::Texture const &texture, sf::Vector2f coordinates,
          std::vector<sf::Vector2f> const &path,
          std::vector<Entity *> &entities, sf::Texture &spawned_texture);

    /**
     * @brief Moves the object along a path, spawns enemies at a set interval.
     *
     * @param delta Delta time to move the object and spawn enemies in relation to.
     */
    void update(sf::Time const &delta) override;
};

#endif