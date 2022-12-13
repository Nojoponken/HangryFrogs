#include "world.h"

World::World()
    : user_interface{}, turret_name{},
      path{}, path_radius{10},
      wave{0}, current_wave{}, spawn_clock{0}
{
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
    textures[0].loadFromFile("../assets/pepeheadsprite.png");
    textures[1].loadFromFile("../assets/fly.png");
    textures[2].loadFromFile("../assets/pepe.png");
    textures[3].loadFromFile("../assets/frost.png");
    textures[4].loadFromFile("../assets/bar.png");
    textures[5].loadFromFile("../assets/frostheadsprite.png");
    textures[6].loadFromFile("../assets/wavebutton.png");
    path = {
        {1080, 325},
        {939, 295},
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

    user_interface.set_coord({0, 768});
    user_interface.set_barsprite(textures[4]);
    user_interface.add_button(textures[6], "Next");
    user_interface.add_button(textures[2], "Pepe");
    user_interface.add_button(textures[3], "Frost");
}
World::~World()
{
    for (auto entity : entities)
    {
        delete entity;
    }
}

void World::draw_objects(sf::RenderWindow &window)
{
    for (Entity *o : entities)
    {
        o->draw(window);
    }
}
void World::draw_bar(sf::RenderWindow &window)
{
    user_interface.draw_bar(window);
}
void World::update_objects(sf::Time delta)
{
    if (!current_wave.empty())
    {
        spawn_clock += delta.asSeconds();
        if (spawn_clock > 1)
        {
            entities.push_back(current_wave.at(current_wave.size() - 1));
            current_wave.pop_back();
            --spawn_clock;
        }
        if (turret_name == "Next")
            turret_name = "";
    }
    else if (turret_name == "Next")
    { /*
         for (int i = 0; i < 3; ++i)
         {
             current_wave.push_back(new McFly{textures[0], path.at(0),
                                              path, entities, textures[1]});

             for (int j = 0; j < 5; ++j)
             {*/
        current_wave.push_back(new Fly{textures[1], path.at(0),
                                       0, path});
        /* }
     }*/
        turret_name = "";
    }

    sort(entities.begin(), entities.end(), [](Entity *a, Entity *b)
         { return a->get_coordinates().y < b->get_coordinates().y; });

    for (Entity *entity : entities)
    {
        Enemy *enemy{dynamic_cast<Enemy *>(entity)};
        if (enemy)
        {
            enemy->set_slow(false);
        }
    }

    for (Entity *o : entities)
    {
        o->update(delta);
    }

    entities.erase(remove_if(entities.begin(), entities.end(), [](Entity *entity)
                             {
                  Enemy *enemy{dynamic_cast<Enemy *>(entity)};
                  if(!enemy)
                  {
                    return false;
                  }
                  if (enemy->get_health() )
                  {
                    return false;
                  } 
                  return true; }),
                   entities.end());
}

void World::place_turret(sf::RenderWindow &window)
{

    sf::Vector2f mousepos{window.mapPixelToCoords(sf::Mouse::getPosition(window))};

    if (!collision(mousepos, 35))
    {
        bool placed{false};
        if (turret_name == "Pepe")
        {
            Pepe pepe{textures[0], mousepos, entities, textures[0]};

            if (!pepe.collision_turrets(pepe.get_radius() - 45, entities))
            {
                entities.push_back(new Pepe{textures[0], mousepos, entities, textures[0]});
                placed = true;
            }
        }
        // entities.push_back(new Pepe{textures[0], mousepos, entities});

        else if (turret_name == "Frost")
        {

            Frost_Pepe frost_pepe{textures[5], mousepos, entities};

            if (!frost_pepe.collision_turrets(frost_pepe.get_radius() - 45, entities))
            {
                entities.push_back(new Frost_Pepe{textures[5], mousepos, entities});
                placed = true;
            }

            // entities.push_back(new Pepe{textures[5], mousepos, entities});
        }
        if (placed)
        {
            turret_name = "";
        }
    }
}

std::string &World::get_turret_name()
{
    return turret_name;
}

/* void World::spawn_enemy()
{
    entities.push_back(
        new Enemy{textures[1], path[0], 32, 1, path});
} */

sf::Vector2f World::get_checkpoint(int index) const
{
    return path[index];
}

User_Interface &World::get_user_interface()
{
    return user_interface;
}

std::vector<Entity *> &World::get_objects()
{
    return entities;
}

float distance(sf::Vector2f a, sf::Vector2f b)
{
    float x{a.x - b.x};
    float y{a.y - b.y};
    return std::sqrt(x * x + y * y);
}

bool World::collision(sf::Vector2f entity_coord, int entity_rad)
{
    int radius = entity_rad + path_radius;

    for (int index{0}; index < path.size() - 1; ++index)
    {
        bool touching_first_point{distance(entity_coord, path[index]) < radius};
        bool touching_second_point{distance(entity_coord, path[index + 1]) < radius};
        if (touching_first_point || touching_second_point)
            return true;

        float dist_between_points{distance(path[index], path[index + 1])};

        float dot_product = (((entity_coord.x - path[index].x) * (path[index + 1].x - path[index].x)) +
                             ((entity_coord.y - path[index].y) * (path[index + 1].y - path[index].y))) /
                            std::pow(dist_between_points, 2);

        sf::Vector2f closest{};
        closest.x = path[index].x + (dot_product * (path[index + 1].x - path[index].x));
        closest.y = path[index].y + (dot_product * (path[index + 1].y - path[index].y));

        if (!(distance(closest, path[index]) > dist_between_points ||
              distance(closest, path[index + 1]) > dist_between_points) &&
            (distance(entity_coord, closest) < radius))
            return true;
    }
    return false;
}
