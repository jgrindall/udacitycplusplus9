
#ifndef POWERUPTYPE_H
#define POWERUPTYPE_H

#include <vector>
#include <future>
#include <mutex>
#include <memory>

enum PowerUpType{
    SLOW_DOWN,  // makes it easier for the player
    GHOST_MODE, // allows passing through walls
    SCORE_BOOST // gives extra points when you eat food
};

int getNumberOfPowerUpTypes() {
    return 3;
}

#endif