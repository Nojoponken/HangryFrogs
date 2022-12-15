#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "turret.h"

/**
 * @brief Clickable object that returns a string when clicked.
 *
 */
class Button
{
private:
    sf::Sprite button_sprite; /// Sprite used to draw button.
    std::string name;         /// String to return when clicked.

public:
    Button(sf::Texture const &texture, std::string const &name);
    ~Button() = default;
    /**
     * @brief Draws the button to the screen.
     *
     * @param window Window to draw the button on.
     */
    void draw_button(sf::RenderWindow &window);
    /**
     * @brief Set the position of the button.
     *
     * @param coordinates Position to set the button to.
     */
    void set_position(sf::Vector2f const &coordinates);
    /**
     * @brief Get the sprite of the button.
     *
     * @return sf::Sprite
     */
    sf::Sprite get_sprite() const;
    /**
     * @brief Get the name of the button.
     *
     * @return std::string
     */
    std::string get_name() const;
};

#endif