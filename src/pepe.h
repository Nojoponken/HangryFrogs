#ifndef PEPE_H
#define PEPE_H

#include "turret.h"
#include "projectile.h"
#include "enemy.h"
/**
 * @brief  Object that represents a Turret that shoot projectiles.
 *
 */
class Pepe : public Turret
{
private:
    /**
     * @brief Function to attack entities of Enemy class if there's a collision.
     *
     * @param delta an sf::Time argument used to set cooldown on attack.
     */
    void attack(sf::Time delta) override;
    /**
     * @brief Cooldown on attack.
     *
     */
    float cooldown;
    /**
     * @brief Projectile texture.
     *
     */
    sf::Texture &projectile_texture;

public:
    Pepe(sf::Texture &texture, sf::Vector2f position,
         std::vector<Entity *> &entities,
         sf::Texture &projectile_texture);
    /**
     * @brief Function to update object.
     *
     * @param delta an sf::Vector2f argument.
     */
    void update(sf::Time delta) override;
};

#endif