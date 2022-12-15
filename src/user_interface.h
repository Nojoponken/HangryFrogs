#ifndef ACTIONBAR_H
#define ACTIONBAR_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "button.h"
#include "turret.h"

/**
 * @brief Object to represent the user interface in the game. Contains all button used by the player.
 *
 */
class User_Interface
{

private:
    /**
     * @brief Stores Button pointers.
     *
     */
    std::vector<Button *> buttons;
    /**
     * @brief User interface sprite.
     *
     */
    sf::Sprite bar_sprite;
    /**
     * @brief Coordinates of user interface bar.
     *
     */
    sf::Vector2f coordinates;

public:
    User_Interface();
    User_Interface(sf::Texture const &texture, sf::Vector2f const &coordinates);
    ~User_Interface();
    /**
     * @brief Function to display the user interface bar in game.
     *
     * @param window an sf::RenderWindow argument.
     */
    void draw_bar(sf::RenderWindow &window);
    /**
     * @brief Function to store a Button object in a specific data container.
     *
     * @param texture an sf::Texture argument containting the buttons texture.
     * @param name a std::string argument. The name of the button.
     */
    void add_button(sf::Texture &texture, std::string const &name);
    /**
     * @brief Function to deter if the user have clicked on the user interface bar.
     *
     * @param window an sf::RenderWindow. Used to get coordinates from mouse click.
     * @param turret_name an std::string by reference. Name changes based on the selected button.
     * @return true
     * @return false
     */
    bool on_bar(sf::RenderWindow &window, std::string &turret_name);
};
#endif