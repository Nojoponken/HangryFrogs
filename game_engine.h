#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "world.h"

class Game_Engine
{
private:
    void new_game(int level);
    void update(sf::Clock &clock, World &world);
    void draw();

public:
    Game_Engine();
    ~Game_Engine();

    void run();
};

#endif