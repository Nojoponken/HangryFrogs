#include "game_engine.h"

Game_Engine::Game_Engine()
{
}

Game_Engine::~Game_Engine()
{
}

void Game_Engine::run()
{

    World world{};
    sf::Clock clock;

    bool place_turret{false};

    sf::RenderWindow window{sf::VideoMode(1024, 876), "Hangry Frogs!"};

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (!world.get_user_interface().on_bar(window, world.get_button_reference()))
                {

                    world.place_turret(window);
                }
            }
        }

        update(clock, world);

        window.clear(sf::Color(130, 230, 150));
        world.draw_background(window);
        world.draw_entities(window);
        world.draw_bar(window);
        window.display();
    }
}

void Game_Engine::update(sf::Clock &clock, World &world)
{
    sf::Time delta = clock.restart();
    world.update_entities(delta);
}