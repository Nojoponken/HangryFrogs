#ifndef ACTIONBAR_H
#define ACTIONBAR_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "button.h"
#include "turret.h"

class Actionbar
{

private:
    std::vector<Button *> buttons;
    sf::Sprite bar_sprite;
    sf::Vector2f coordinates;
    int button_index;

public:
    Actionbar();
    Actionbar(sf::Texture &texture, sf::Vector2f const &coordinates);
    ~Actionbar();
    void set_barsprite(sf::Texture &texture);
    void set_coord(sf::Vector2f coord);
    void draw_bar(sf::RenderWindow &window);
    void add_button(sf::Texture &texture, std::string const &name);

    bool on_bar(sf::RenderWindow &window, std::string &turret_name);
};
#endif