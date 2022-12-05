#include "entity.h"

Entity::Entity(sf::Texture &texture, sf::Vector2f coordinates, float radius)
    : sprite{}, coordinates{coordinates}, direction{1, 0}, radius{radius}
{
    sprite.setTexture(texture);
    sprite.setTextureRect({0, 0, 256, 256});
    sprite.setScale(radius / 128, radius / 128);
}

void Entity::draw(sf::RenderWindow &window)
{
    float current_angle{std::atan2(direction.x, direction.y)}; // gets direction in radians

    current_angle /= M_PI; // converts from radians to an integer between 0 and 7
    current_angle *= 4;
    current_angle += 4;
    current_angle = round(current_angle);
    current_angle -= (current_angle == 8) * 8;

    current_angle *= 256; // converts to sprite coordinates on sprite sheet
    int draw_angle = current_angle;

    sprite.setTextureRect({draw_angle, 0, 256, 256}); // sets texture

    sprite.setPosition(coordinates.x - radius, coordinates.y - radius);

    window.draw(sprite);
}
