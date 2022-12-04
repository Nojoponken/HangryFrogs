#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "object.h"
#include "turret.h"

class World
{
private:
    int health;
    int resource;
    std::vector<Object *> objects;
    int wave;
    std::vector<sf::Texture> textures;
    // vector<Enemy> current_wave{};

public:
    World();
    void update_objects(sf::Time delta);
    void draw_objects(sf::RenderWindow &window);
    void spawn_turret(sf::Vector2f position);
};

#endif