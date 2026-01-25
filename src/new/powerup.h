
#ifndef POWERUP_H
#define POWERUP_H

#include "poweruptypes.h"

#include <vector>
#include <future>
#include <mutex>
#include <memory>

struct Point{
    int x;
    int y;
};

class PowerUp
{
public:
    PowerUp(PowerUpType type, Point position);
    PowerUpType getType();
    Point getPosition();
    static int getNumberOfTypes();

private:
    PowerUpType _type;
    Point _position;
};

#endif