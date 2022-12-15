#include "user_interface.h"
#include <iostream>
User_Interface::User_Interface()
    : bar_sprite{}, coordinates{}, buttons{}
{
}
User_Interface::User_Interface(sf::Texture const &texture, sf::Vector2f const &coordinates)
    : bar_sprite{}, coordinates{coordinates}, buttons{}
{
    bar_sprite.setTexture(texture);
}
User_Interface::~User_Interface()
{
    for (auto button : buttons)
    {
        delete button;
    }
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

bool User_Interface::on_bar(sf::RenderWindow &window, std::string &button_reference)
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
                    button_reference = button->get_name();
                    return true;
                }

                break;
            }
        }
        return true;
    }
    return false;
}
