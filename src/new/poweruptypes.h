
#ifndef POWERUPTYPE_H
#define POWERUPTYPE_H

#include <vector>
#include <future>
#include <mutex>
#include <memory>

enum PowerUpType{
    SLOW_DOWN,  // makes it easier for the player!
    GHOST_MODE, // allows passing through walls - not done yet
    EXTRA_SCORE // extra points
};

#endif