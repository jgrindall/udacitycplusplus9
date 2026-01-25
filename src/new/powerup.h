
#ifndef POWERUP_H
#define POWERUP_H

#include <vector>
#include <future>
#include <mutex>
#include <memory>

struct Point{
    int x;
    int y;
};

enum PowerUpType{
    SLOW_DOWN,  // makes it easier for the player
    GHOST_MODE, // allows passing through walls
    SCORE_BOOST // gives extra points when you eat food
};

class PowerUp
{
public:
    PowerUp(PowerUpType type, Point position);
    PowerUpType getType();
    Point getPosition();

private:
    PowerUpType _type;
    Point _position;
};

#endif