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

    /*    sf::Texture btn1{};
       sf::Texture btn2{};
       sf::Texture actbar{};
       btn1.loadFromFile("../pepe.png");
       btn2.loadFromFile("../frost.png");
       actbar.loadFromFile("../bar.png");
       Actionbar actionbar{actbar, {0, 758}};
       actionbar.add_button(btn1, );
       actionbar.add_button(btn2); */

    /*     sf::Texture turr{};
        turr.loadFromFile("../pepeheadsprite.png");
        sf::Sprite turret{turr};
        sf::IntRect rectTurret{0, 0, 256, 256};
        turret.setTextureRect(rectTurret);
        turret.setPosition(50, 50); */
    World world{};
    world.spawn_turret({777, 200});
    world.spawn_turret({630, 470});
    world.spawn_turret({477, 177});
    world.spawn_enemy();
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
                if (!world.get_actionbar().on_bar(window, world.get_turret_name()))
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