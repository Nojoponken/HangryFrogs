
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <iostream>

class Entity
{
private:
    float radius;      /// Radius of the entity hit-circle and sprite.
    sf::Sprite sprite; /// Sprite drawn at the entity position.

public:
    Entity(sf::Texture const &texture, sf::Vector2f const &coordinates, float const radius);
    virtual ~Entity() = default;

    /**
     * @brief Pure virtual, updates entity.
     *
     * @param delta Delta time argument.
     */
    virtual void update(sf::Time const &delta) = 0;

    /**
     * @brief Draw entity sprite.
     *
     * @param window Window that is drawn to.
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Check collision with other entity given a radius.
     *
     * @param rad Radius to use.
     * @param other Other entity to collide with.
     * @return true
     * @return false
     */
    virtual bool collision(float const rad, Entity const &other) const;
    /**
     * @brief Calculate distance to position.
     *
     * @param other Other position.
     * @return float
     */
    float distance(sf::Vector2f const &other) const;

    /**
     * @brief Get the coordinate of the entity.
     *
     * @return sf::Vector2f
     */
    sf::Vector2f get_coordinates() const;
    /**
     * @brief Get the radius of the entity.
     *
     * @return float
     */
    float get_radius() const;

protected:
    sf::Vector2f direction;   /// Direction the entity points in.
    sf::Vector2f coordinates; /// Position of the entity.
};

#endif