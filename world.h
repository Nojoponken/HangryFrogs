#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "entity.h"
#include "turret.h"
#include "pepe.h"
#include "enemy.h"
#include "actionbar.h"

/**
 * @brief A class to represent the game
 *
 */
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
    /**
     * @brief Function that returns a vector by reference that stores Turret objects in queue to be placed.
     *
     * @return std::vector<Turret *>&
     */
    std::vector<Turret *> &get_turrets_to_place();
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
    Actionbar &get_actionbar();
    /**
     * @brief Function that returns a vector by reference containing all the entities displayed in the game.
     *
     * @return std::vector<Entity *>& a vector containing Entity pointers.
     */
    std::vector<Entity *> &get_objects();
};

#endif