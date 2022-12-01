#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

int main()
{
  sf::RenderWindow window{sf::VideoMode(1024, 768), "Hello World!"};
  std::map<std::string const, bool> isPressed{
      std::pair<std::string const, bool>{"up", false},
      std::pair<std::string const, bool>{"right", false},
      std::pair<std::string const, bool>{"down", false},
      std::pair<std::string const, bool>{"left", false}};

  sf::Clock clock;
  sf::Texture backg{};
  backg.loadFromFile("windowsxp.jpg");
  sf::Sprite background{backg};

  sf::Texture txt{};
  txt.loadFromFile("fly.png");
  sf::Sprite player{txt};

  float x{0};
  float y{0};
  float speed{50000.0f};

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed)
      {
        switch (event.key.code)
        {
        case sf::Keyboard::W:
          isPressed["up"] = true;
          break;
        case sf::Keyboard::D:
          isPressed["right"] = true;
          break;
        case sf::Keyboard::S:
          isPressed["down"] = true;
          break;
        case sf::Keyboard::A:
          isPressed["left"] = true;
          break;
        }
      }
      if (event.type == sf::Event::KeyReleased)
      {
        switch (event.key.code)
        {
        case sf::Keyboard::W:
          isPressed["up"] = false;
          break;
        case sf::Keyboard::D:
          isPressed["right"] = false;
          break;
        case sf::Keyboard::S:
          isPressed["down"] = false;
          break;
        case sf::Keyboard::A:
          isPressed["left"] = false;
          break;
        }
      }
    }

    // UPDATE
    sf::Time delta = clock.restart();

    if (isPressed["left"])
    {
      x -= delta.asSeconds() * speed;
    }
    if (isPressed["right"])
    {
      x += delta.asSeconds() * speed;
    }
    if (isPressed["up"])
    {
      y -= delta.asSeconds() * speed;
    }
    if (isPressed["down"])
    {
      y += delta.asSeconds() * speed;
    }

    std::cout << (1.0f / delta.asSeconds()) << std::endl;

    player.setPosition(x, y);

    if (x > 1024)
    {
      x = -1000;
    }
    if (x < -1000)
    {
      x = 1024;
    }
    if (y > 768)
    {
      y = -800;
    }
    if (y < -800)
    {
      y = 768;
    }

    // DRAW
    window.clear();

    window.draw(background);

    window.draw(player);

    window.display();
  }
  return 0;
}
