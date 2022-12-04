
#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include <iostream>

class Object
{
private:
    float radius;
    sf::Sprite sprite;

public:
    Object(sf::Texture &texture, sf::Vector2f coordinates);
    virtual void update(sf::Time delta) = 0;
    void draw(sf::RenderWindow &window);

protected:
    sf::Vector2f direction;
    sf::Vector2f coordinates;
    bool collide();
};

#endif