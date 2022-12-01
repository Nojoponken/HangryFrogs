#include <SFML>
#ifndef OBJECT_H
#define OBJECT_H

class Object
{
private:
    sf::Vector2f coordinates;
    float radius;
    float direction;
    sf::Sprite sprite;

public:
    void update() = 0;
    void draw();

protected:
    bool collide();
};

#endif