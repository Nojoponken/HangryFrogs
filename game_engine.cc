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
    backg.loadFromFile("../bg.png");
    sf::Sprite background{backg};

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

    sf::RenderWindow window{sf::VideoMode(1024, 758), "Hangry Frogs!"};
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        update(clock, world);

        window.clear();
        window.draw(background);

        world.draw_objects(window);

        window.display();
    }
}

void Game_Engine::update(sf::Clock &clock, World &world)
{
    sf::Time delta = clock.restart();
    world.update_objects(delta);
}