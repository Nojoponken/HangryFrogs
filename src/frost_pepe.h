#ifndef FROST_PEPE_H
#define FROST_PEPE_H

#include "turret.h"

/**
 * @brief Object that represents a Turret that slows entities of Enemy class.
 *
 */
class Frost_Pepe : public Turret
{
private:
    /**
     * @brief  Function to attack entities of Enemy class if there's a collision.
     *
     * @param delta an sf::Time argument
     */
    virtual void attack(sf::Time delta);

public:
    Frost_Pepe(sf::Texture &texture, sf::Vector2f position, std::vector<Entity *> &entities);
    /**
     * @brief Function to update object.
     *
     * @param delta an sf::Vector2f argument.
     */
    void update(sf::Time delta) override;
};

#endif
