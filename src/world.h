#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

#include "entity.h"
#include "turret.h"
#include "pepe.h"
#include "frost_pepe.h"
#include "user_interface.h"
#include "enemy.h"
#include "fly.h"
#include "mcfly.h"

/**
 * @brief A class to represent the game
 *
 */
class World
{
private:
    std::vector<Entity *> entities;
    std::vector<Entity *> current_wave;
    int wave;
    float spawn_clock;
    std::vector<sf::Texture> textures;
    std::vector<sf::Vector2f> path;
    int path_radius;
    User_Interface user_interface;
    std::string turret_name;

public:
    World();
    ~World();
    /**
     * @brief Function to update all entities inside the class.
     *
     * @param delta - an sf::Time argument.
     */
    void update_objects(sf::Time delta);
    /**
     * @brief Function to display all the entitites stored in a specific data container.
     *
     * @param window an sf::RenderWindow argument.
     */
    void draw_objects(sf::RenderWindow &window);
    /**
     * @brief Function to display the actionbar in the game that the user interacts with to build turrets.
     *
     * @param window an sf::RenderWindow argument.
     */
    void draw_bar(sf::RenderWindow &window);
    /**
     * @brief Function to store a new Turret class object into a specific data container.
     *
     * @param position an sf::Vector2f argument.
     */
    void spawn_turret(sf::Vector2f position);
    /**
     * @brief Function to store a new Turret class object into a specific data container.
     *
     * @param window an sf::Vector2f argument.
     */
    void place_turret(sf::RenderWindow &window);

    std::string &get_turret_name();
    /**
     * @brief Function to store a new Enemy class object in a specific data container.
     *
     */
    void spawn_enemy();
    /**
     * @brief Function that returns a certain coordinate pair on index in a specific data container wich represent the
     *        path that is the displayed in the game.
     * @param index an integer argument.
     * @return sf::Vector2f The coordinate
     */
    sf::Vector2f get_checkpoint(int index) const;
    /**
     * @brief Function that return the actionbar objects by reference.
     *
     * @return Actionbar& The Action bar class.
     */
    User_Interface &get_user_interface();
    /**
     * @brief Function that returns a vector by reference containing all the entities displayed in the game.
     *
     * @return std::vector<Entity *>& a vector containing Entity pointers.
     */
    std::vector<Entity *> &get_objects();

    bool collision(sf::Vector2f entity_coord, int entity_rad);
};

#endif