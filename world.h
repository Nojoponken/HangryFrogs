#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "entity.h"
#include "turret.h"
#include "pepe.h"
#include "enemy.h"

class World
{
private:
    int health;
    int resource;
    std::vector<Entity *> objects;
    int wave;
    std::vector<sf::Texture> textures;
    std::vector<sf::Vector2f> path;
    // vector<Enemy> current_wave{};
public:
    World();
    void update_objects(sf::Time delta);
    void draw_objects(sf::RenderWindow &window);
    void spawn_turret(sf::Vector2f position);
    void spawn_enemy();
    sf::Vector2f get_checkpoint(int index) const;
};

#endif