#include "game_engine.h"

Game_Engine::Game_Engine()
{
}

Game_Engine::~Game_Engine()
{
}

void Game_Engine::run()
{
    sf::Texture backg{};
    backg.loadFromFile("../assets/bg.png");
    sf::Sprite background{backg};

    World world{};
    sf::Clock clock;

    bool place_turret{false};

    sf::RenderWindow window{sf::VideoMode(1024, 858), "Hangry Frogs!"};

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
                if (!world.get_user_interface().on_bar(window, world.get_turret_name()))
                {

                    world.place_turret(window);
                }
            }
        }

        update(clock, world);

        window.clear();
        window.draw(background);

        world.draw_objects(window);
        world.draw_bar(window);
        window.display();
    }
}

void Game_Engine::update(sf::Clock &clock, World &world)
{
    sf::Time delta = clock.restart();
    world.update_objects(delta);
}