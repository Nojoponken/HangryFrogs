#include "world.h"

World::World()
    : health{100}, resource{80}, wave{0}
{
    textures.push_back(sf::Texture{});
    textures[0].loadFromFile("../pepeheadsprite.png");
}

void World::draw_objects(sf::RenderWindow &window)
{
    for (Object *o : objects)
    {
        o->draw(window);
    }
}

void World::update_objects(sf::Time delta)
{
    for (Object *o : objects)
    {
        o->update(delta);
    }
}

void World::spawn_turret(sf::Vector2f position)
{
    objects.push_back(
        new Turret{textures[0], position});
}