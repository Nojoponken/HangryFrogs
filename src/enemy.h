#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>

#include "entity.h"

/**
 * @brief Abstract class representing enemies that inherits from Entity.
 *
 */
class Enemy : public Entity
{
private:
    int health;     /// Amount of damage that the enemy can take.
    int speed;      /// Speed at which the enemy can move.
    bool slowed;    /// Bool that halves the speed while true.
    int checkpoint; /// Tracks current targeted path checkpoints index.

public:
    Enemy(sf::Texture const &texture, sf::Vector2f const &coordinates,
          float const radius, int const health,
          int const checkpoint, std::vector<sf::Vector2f> const &path, int const speed);
    virtual ~Enemy() = default;
    /**
     * @brief Pure virtual, updates the enemy.
     *
     * @param delta Delta time argument.
     */
    virtual void update(sf::Time const &delta) override = 0;
    /**
     * @brief Lowers enemy health by one.
     *
     */
    void take_damage();
    /**
     * @brief Get the health of the enemy.
     *
     * @return int
     */
    int get_health() const;
    /**
     * @brief Get the distance left to the last checkpoint.
     *
     * @return float
     */
    float get_distance_left() const;
    /**
     * @brief Set the slow bool.
     *
     * @param slow Bool argument to set slow to.
     */
    void set_slow(bool const slow);
    /**
     * @brief Points direction vector towards the target checkpoint, sets the magnitude according to speed.
     *
     * @param delta Delta time to relate speed to.
     */
    void point_to_path(sf::Time const &delta);
    /**
     * @brief Get the current checkpoints index.
     *
     * @return int
     */
    int get_checkpoint() const;

protected:
    /**
     * @brief Path consiting of a number of checkpoints to pass through.
     *
     */
    std::vector<sf::Vector2f> const &path;
};

#endif
