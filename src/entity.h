
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <iostream>

class Entity
{
private:
    int radius; ///
    sf::Sprite sprite;

public:
    Entity(sf::Texture &texture, sf::Vector2f coordinates, int radius);
    virtual ~Entity() = default;
    virtual void update(sf::Time delta) = 0;
    void draw(sf::RenderWindow &window);
    float distance(sf::Vector2f other) const;

    sf::Vector2f get_coordinates() const;
    int get_radius() const;
    bool collision(Entity const &other);

protected:
    sf::Vector2f direction;
    sf::Vector2f coordinates;
};

#endif