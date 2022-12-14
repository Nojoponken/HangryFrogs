#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "world.h"

/**
 * @brief
 *
 */
class Game_Engine
{
private:
     /**
     * @brief Function that contains all the operations in the update step of a frame.
     *
     * @param clock Clock object that is used to generate a delta in the function.
     * @param world World object that should be updated.
     */
    void update(sf::Clock &clock, World &world);

    /**
     * @brief Function that contains all the operations in the draw step of a frame.
     *
     */
    void draw();

public:
    Game_Engine();
    ~Game_Engine();

    /**
     * @brief Function that runs the game loop.
     *
     */
    void run();
};

#endif