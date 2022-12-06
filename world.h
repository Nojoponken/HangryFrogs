#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "entity.h"
#include "turret.h"
#include "pepe.h"
#include "enemy.h"
#include "actionbar.h"

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
    Actionbar actionbar;
    std::vector<Turret *> turrets_to_place;

public:
    World();
    ~World();
    void update_objects(sf::Time delta);
    void draw_objects(sf::RenderWindow &window);
    void draw_bar(sf::RenderWindow &window);
    void spawn_turret(sf::Vector2f position);
    void place_turret(sf::RenderWindow &window);
    std::vector<Turret *> &get_turrets_to_place();
    void spawn_enemy();
    sf::Vector2f get_checkpoint(int index) const;
    Actionbar &get_actionbar();
    std::vector<Entity *> &get_objects();
};

#endif