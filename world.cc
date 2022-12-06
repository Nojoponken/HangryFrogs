#include "world.h"

World::World()
    : health{100}, resource{80}, wave{0}, actionbar{}, turrets_to_place{}
{
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures[0].loadFromFile("../pepeheadsprite.png");
    textures[1].loadFromFile("../flysprite.png");
    textures[2].loadFromFile("../pepe.png");
    textures[3].loadFromFile("../frost.png");
    textures[4].loadFromFile("../bar.png");
    path = {{939, 295},
            {902, 267},
            {892, 242},
            {892, 162},
            {880, 123},
            {855, 101},
            {808, 90},
            {767, 90},
            {728, 108},
            {704, 137},
            {660, 212},
            {597, 220},
            {569, 202},
            {561, 104},
            {537, 73},
            {514, 68},
            {453, 68},
            {416, 78},
            {407, 110},
            {393, 182},
            {351, 247},
            {167, 273},
            {109, 300},
            {82, 338},
            {86, 377},
            {121, 397},
            {616, 429},
            {662, 432},
            {700, 462},
            {721, 508},
            {692, 552},
            {336, 518},
            {142, 508},
            {103, 537},
            {103, 587},
            {133, 616},
            {361, 633},
            {509, 655},
            {664, 669},
            {729, 683},
            {774, 800}};

    actionbar.set_coord({0, 758});
    actionbar.set_barsprite(textures[4]);
    actionbar.add_button(textures[2], new Pepe{textures[0], {0, 0}});
    actionbar.add_button(textures[3], new Pepe{textures[0], {0, 0}});
}
World::~World()
{
    for (auto entity : objects)
    {
        delete entity;
    }
}

void World::draw_objects(sf::RenderWindow &window)
{
    for (Entity *o : objects)
    {
        o->draw(window);
    }
}
void World::draw_bar(sf::RenderWindow &window)
{
    actionbar.draw_bar(window);
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
        new Pepe{textures[0], position});
}

void World::place_turret(sf::RenderWindow &window)
{
    if (!turrets_to_place.empty())
    {
        sf::Vector2f mousepos{window.mapPixelToCoords(sf::Mouse::getPosition(window))};
        turrets_to_place[turrets_to_place.size() - 1]->set_position(mousepos);
        objects.push_back(turrets_to_place[turrets_to_place.size() - 1]);
        turrets_to_place.pop_back();
    }
}
std::vector<Turret *> &World::get_turrets_to_place()
{
    return turrets_to_place;
}
void World::spawn_enemy()
{
    objects.push_back(
        new Enemy{textures[1], {1024, 317}, 32, 1, path});
}

sf::Vector2f World::get_checkpoint(int index) const
{
    return path[index];
}

Actionbar &World::get_actionbar()
{
    return actionbar;
}

std::vector<Entity *> &World::get_objects()
{
    return objects;
}
