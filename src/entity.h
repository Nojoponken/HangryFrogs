
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <iostream>

class Entity
{
private:
    float radius; ///
    sf::Sprite sprite;

public:
    /**
     * @brief Construct a new Entity object
     *
     * @param texture
     * @param coordinates
     * @param radius
     */
    Entity(sf::Texture &texture, sf::Vector2f &coordinates, float radius);
    virtual ~Entity() = default;
    virtual void update(sf::Time delta) = 0;
    void draw(sf::RenderWindow &window);
    float distance(sf::Vector2f other) const;

    sf::Vector2f get_coordinates() const;
    float get_radius() const;
    virtual bool collision(int const rad, Entity const &other);

protected:
    sf::Vector2f direction;
    sf::Vector2f coordinates;
};

#endif