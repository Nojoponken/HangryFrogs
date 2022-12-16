#include "world.h"

World::World()
    : entities{}, last_button_pressed{},
      path{}, path_radius{10},
      current_wave{}, spawn_clock{0}
{
    textures.push_back(sf::Texture{});
    textures.push_back(sf::Texture{});
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
    textures[7].loadFromFile("../assets/bg.png");
    textures[8].loadFromFile("../assets/fireheadsprite.png");

    std::ifstream ifs{"../src/path.txt"};

    while (true)
    {
        float x{};
        float y{};

        ifs >> x;
        ifs >> y;

        if (ifs.eof())
            break;

        path.push_back(sf::Vector2f{x, y});
    }
    user_interface = User_Interface{textures[4], {0, 748}};
    user_interface.add_button(textures[6], "Next");
    user_interface.add_button(textures[2], "Pepe");
    user_interface.add_button(textures[3], "Frost");
}
World::~World()
{

    for (Entity *entity : entities)
    {
        delete entity;
    }
    for (Entity *entity : current_wave)
    {
        delete entity;
    }
}
void World::draw_background(sf::RenderWindow &window)
{

    window.draw(sf::Sprite{textures[7]});
}
void World::draw_entities(sf::RenderWindow &window)
{
    for (Entity *entity : entities)
    {
        entity->draw(window);
    }
}
void World::draw_bar(sf::RenderWindow &window)
{
    user_interface.draw_bar(window);
}
void World::update_entities(sf::Time const &delta)
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
        if (last_button_pressed == "Next")
            last_button_pressed = "";
    }
    else if (last_button_pressed == "Next")
    {
        for (int i = 0; i < 3; ++i)
        {
            current_wave.push_back(new McFly{textures[1], path.at(0),
                                             path, entities, textures[1]});

            for (int j = 0; j < 5; ++j)
            {
                current_wave.push_back(new Fly{textures[1], path.at(0),
                                               0, path});
            }
        }
        last_button_pressed = "";
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

    for (Entity *entity : entities)
    {
        Enemy *enemy{dynamic_cast<Enemy *>(entity)};
        if (!enemy)
        {
            entity->update(delta);
        }
    }

    for (Entity *entity : entities)
    {
        Enemy *enemy{dynamic_cast<Enemy *>(entity)};
        if (enemy)
        {
            enemy->update(delta);
        }
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
                  delete entity;
                  
                  return true; }),
                   entities.end());

    entities.erase(remove_if(entities.begin(), entities.end(), [](Entity *entity)
                             {   
                Projectile * projectile{dynamic_cast<Projectile*>(entity)};
                if(!projectile)
                  {
                    return false;
                  }

                if(!projectile->get_projectile_hit())
                  {
                    return false;
                  }
                  delete entity;
                  return true ; }),
                   entities.end());
}

void World::place_turret(sf::RenderWindow &window)
{

    sf::Vector2f mousepos{window.mapPixelToCoords(sf::Mouse::getPosition(window))};

    if (!collision(mousepos, 35))
    {
        bool placed{false};
        if (last_button_pressed == "Pepe")
        {
            Pepe pepe{textures[0], mousepos, entities, textures[8]};

            if (!pepe.collision_turrets(pepe.get_radius() - 45))
            {
                entities.push_back(new Pepe{textures[0], mousepos, entities, textures[8]});
                placed = true;
            }
        }

        else if (last_button_pressed == "Frost")
        {

            Frost_Pepe frost_pepe{textures[5], mousepos, entities};

            if (!frost_pepe.collision_turrets(frost_pepe.get_radius() - 45))
            {
                entities.push_back(new Frost_Pepe{textures[5], mousepos, entities});
                placed = true;
            }
        }
        if (placed)
        {
            last_button_pressed = "";
        }
    }
}

std::string &World::get_button_reference()
{
    return last_button_pressed;
}

sf::Vector2f World::get_checkpoint(int index) const
{
    return path[index];
}

User_Interface &World::get_user_interface()
{
    return user_interface;
}

float distance(sf::Vector2f a, sf::Vector2f b)
{
    float x{a.x - b.x};
    float y{a.y - b.y};
    return std::sqrt(x * x + y * y);
}

bool World::collision(sf::Vector2f const &entity_coord, int const entity_rad)
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
