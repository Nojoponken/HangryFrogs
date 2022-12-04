#include <SFML/Graphics.hpp>
#include <iostream>

#include "game_engine.h"

using namespace std;

int main(int argc, char *argv[])
{
    Game_Engine game{};
    game.run();
    return 0;
}