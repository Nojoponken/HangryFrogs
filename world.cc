#include "world.h"

World::World()
    : health{100}, resource{80}, wave{0}
{
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures[0].loadFromFile("../pepeheadsprite.png");
    textures[1].loadFromFile("../flysprite.png");
    path = {{1024, 300}, {100, 300}, {900, 150}, {800, 758}};
}

void World::draw_objects(sf::RenderWindow &window)
{
    for (Entity *o : objects)
    {
        o->draw(window);
    }
}

void World::update_objects(sf::Time delta)
{

    for (Entity *o : objects)
    {
        o->update(delta);
    }
}

void World::spawn_turret(sf::Vector2f position)
{
    objects.push_back(
        new Pepe{textures[0], position, 64});
}

void World::spawn_enemy()
{
    objects.push_back(
        new Enemy{textures[1], {1024, 500}, 32, 1, path});
}

sf::Vector2f World::get_checkpoint(int index) const
{
    return path[index];
}