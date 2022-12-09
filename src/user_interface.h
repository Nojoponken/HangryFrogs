#ifndef ACTIONBAR_H
#define ACTIONBAR_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "button.h"
#include "turret.h"

class User_Interface
{

private:
    std::vector<Button *> buttons;
    sf::Sprite bar_sprite;
    sf::Vector2f coordinates;
    int button_index;

public:
    User_Interface();
    User_Interface(sf::Texture &texture, sf::Vector2f const &coordinates);
    ~User_Interface();
    void set_barsprite(sf::Texture &texture);
    void set_coord(sf::Vector2f coord);
    void draw_bar(sf::RenderWindow &window);
    void add_button(sf::Texture &texture, std::string const &name);

    bool on_bar(sf::RenderWindow &window, std::string &turret_name);
};
#endif