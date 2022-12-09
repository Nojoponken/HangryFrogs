#include "user_interface.h"
#include <iostream>
User_Interface::User_Interface()
    : bar_sprite{}, coordinates{}, buttons{}
{
}
User_Interface::User_Interface(sf::Texture &texture, sf::Vector2f const &coordinates)
    : bar_sprite{texture}, coordinates{coordinates}, buttons{}
{
}
User_Interface::~User_Interface()
{
    for (auto button : buttons)
    {
        delete button;
    }
}

void User_Interface::set_barsprite(sf::Texture &texture)
{
    bar_sprite.setTexture(texture);
}
void User_Interface::set_coord(sf::Vector2f coord)
{
    coordinates = coord;
}

void User_Interface::draw_bar(sf::RenderWindow &window)
{

    bar_sprite.setPosition(coordinates);
    window.draw(bar_sprite);
    float x_pos{coordinates.x};
    for (auto button : buttons)
    {
        button->set_position({x_pos, coordinates.y});
        button->draw_button(window);
        x_pos += 150;
    }
}

void User_Interface::add_button(sf::Texture &texture, std::string const &name)
{
    buttons.push_back(new Button{texture, name});
}

/* void Actionbar::on_bar(sf::RenderWindow &window, Turret *turret)
{
    sf::FloatRect bar_bounds{bar_sprite.getGlobalBounds()};
    sf::Vector2f mousepos{window.mapPixelToCoords(sf::Mouse::getPosition(window))};
    if (bar_bounds.contains(mousepos))
    {

        for (auto button : buttons)
        {
            if (button->get_sprite().getGlobalBounds().contains(mousepos.x, mousepos.y))
            {

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    button->set_turret_pos(window);
                    delete turret;
                    turret = &button->get_turret();
                }

                break;
            }
        }
    }
} */

bool User_Interface::on_bar(sf::RenderWindow &window, std::string &turret_name)
{
    sf::FloatRect bar_bounds{bar_sprite.getGlobalBounds()};
    sf::Vector2f mousepos{window.mapPixelToCoords(sf::Mouse::getPosition(window))};
    if (bar_bounds.contains(mousepos))
    {

        for (auto button : buttons)
        {
            if (button->get_sprite().getGlobalBounds().contains(mousepos.x, mousepos.y))
            {

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    turret_name = button->get_name();
                    return true;
                }

                break;
            }
        }
        return true;
    }
    return false;
}
