#ifndef TURRET_H
#define TURRET_H

#include <cmath>

#include "entity.h"
#include "enemy.h"

class World;

/**
 * @brief Abstract class that represents turrets in game. Inherits from Entity.
 *
 */
class Turret : public Entity
{
private:
public:
    Turret(sf::Texture &texture, sf::Vector2f coordinates, float radius, float attack_radius, std::vector<Entity *> &entities);
    virtual ~Turret() = default;
    /**
     * @brief Function to update object.
     *
     * @param delta an sf::Vector2f argument.
     */
    virtual void update(sf::Time delta) override = 0;
    /**
     * @brief Function to deter if user is trying place a turret on another turret in game.
     *
     * @param rad an int argument based on object radius.
     * @return true
     * @return false
     */
    virtual bool collision_turrets(int const rad); // Kanske flytta till collision i world
    /**
     * @brief Function to set position of turret.
     *
     * @param coord an sf::Vector2f argument.
     */
    void set_position(sf::Vector2f coord);

protected:
    /**
     * @brief The turrets attack radius.
     *
     */
    float attack_radius;
    /**
     * @brief Function to attack entities of Enemy class if there's a collision.
     *
     * @param delta an sf::Time argument.
     */
    virtual void attack(sf::Time delta) = 0;

    /**
     * @brief Stores all entities in game, used for attack and collision.
     *
     */
    std::vector<Entity *> &entities;
};

#endif