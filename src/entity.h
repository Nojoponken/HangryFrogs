
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
    Entity(sf::Texture &texture, sf::Vector2f coordinates, float radius);
    virtual ~Entity() = default;
    virtual void update(sf::Time delta) = 0;
    void draw(sf::RenderWindow &window);
    sf::Vector2f get_coordinates();

protected:
    sf::Vector2f direction;
    sf::Vector2f coordinates;
    bool collide();
};

#endif