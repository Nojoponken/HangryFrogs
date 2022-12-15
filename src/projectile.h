#ifndef PROJECT_H
#define PROJECT_H

#include "entity.h"
#include "enemy.h"

/**
 * @brief Projectile that travels at a constant speed and damages enemies. Inherits Entity.
 *
 */
class Projectile : public Entity
{
private:
    std::vector<Entity *> &entities; /// Vector to search for enemies in.
    bool projectile_hit;             /// True if the enemy has hit a target.

public:
    Projectile(sf::Texture const &texture, sf::Vector2f const &coordinates,
               float const radius, sf::Vector2f const &velocity,
               std::vector<Entity *> &entities);
    /**
     * @brief Moves the projectile at a constant speed, damages enemies hit.
     *
     * @param delta Delta time to move the projectile in relation to.
     */
    void update(sf::Time const &delta) override;
    /**
     * @brief Checks if the projectile has hit an enemy. Damages hit enemies and updates projectile_hit.
     *
     */
    void hit();
    /**
     * @brief Get the value  of projectile_hit.
     *
     * @return true
     * @return false
     */
    bool get_projectile_hit() const;
};

#endif