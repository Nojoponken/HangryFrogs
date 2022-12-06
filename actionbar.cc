#include "actionbar.h"
#include <iostream>
Actionbar::Actionbar()
    : bar_sprite{}, coordinates{}, buttons{}
{
}
Actionbar::Actionbar(sf::Texture &texture, sf::Vector2f const &coordinates)
    : bar_sprite{texture}, coordinates{coordinates}, buttons{}
{
}
Actionbar::~Actionbar()
{
    for (auto button : buttons)
    {
        delete button;
    }
}

void Actionbar::set_barsprite(sf::Texture &texture)
{
    bar_sprite.setTexture(texture);
}
void Actionbar::set_coord(sf::Vector2f coord)
{
    coordinates = coord;
}

void Actionbar::draw_bar(sf::RenderWindow &window)
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

void Actionbar::add_button(sf::Texture &texture, Turret *turret)
{
    buttons.push_back(new Button{texture, turret});
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

bool Actionbar::on_bar(sf::RenderWindow &window, std::vector<Turret *> &turrets_to_place)
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
                    turrets_to_place.push_back(button->get_turret());
                    return true;
                }

                break;
            }
        }
        return true;
    }
    return false;
}
