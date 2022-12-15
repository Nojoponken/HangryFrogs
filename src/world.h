#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>

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
    std::vector<Entity *> entities;     /// Vector containing all entities in the game.
    std::vector<Entity *> current_wave; /// Vector containing all enemies that have yet to be spawned in the current wave.
    float spawn_clock;                  /// Seconds since last spawn.
    std::vector<sf::Texture> textures;  /// Vector storing all the games textures.
    std::vector<sf::Vector2f> path;     /// Path that enemies follow.
    int path_radius;                    /// Radius of the path that turrets may not be placed on.
    User_Interface user_interface;      /// User interface for placing turrets and starting waves.
    std::string last_button_pressed;    /// Return value of the last button that was pressed.

public:
    World();
    ~World();
    /**
     * @brief Renders the background image.
     *
     * @param window an sf::RenderWindow argument.
     */
    void draw_background(sf::RenderWindow &window);
    /**
     * @brief Function to display all the entitites stored in a specific data container.
     *
     * @param window an sf::RenderWindow argument.
     */
    void draw_entities(sf::RenderWindow &window);
    /**
     * @brief Function to display the actionbar in the game that the user interacts with to build turrets.
     *
     * @param window an sf::RenderWindow argument.
     */
    void draw_bar(sf::RenderWindow &window);
    /**
     * @brief Function to update all entities inside the class.
     *
     * @param delta - an sf::Time argument.
     */
    void update_entities(sf::Time const &delta);
    /**
     * @brief Function to store a new Turret class object into a specific data container.
     *
     * @param window an sf::Vector2f argument.
     */
    void place_turret(sf::RenderWindow &window);

    std::string &get_button_reference();
    /**
     * @brief Function that returns a certain coordinate pair on index in a specific data container wich represent the
     *        path that is the displayed in the game.
     * @param index an integer argument.
     * @return sf::Vector2f The coordinate
     */
    sf::Vector2f get_checkpoint(int constindex) const;
    /**
     * @brief Function that return the actionbar objects by reference.
     *
     * @return Actionbar& The Action bar class.
     */
    User_Interface &get_user_interface();

    /**
     * @brief Collision between an entity and the path.
     *
     * @param entity_coord Entity position.
     * @param entity_rad Entity radius.
     * @return true
     * @return false
     */
    bool collision(sf::Vector2f const &entity_coord, int const entity_rad);
};

#endif