
#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <random>

#include "powerup.h"

/* Implementation of class "PowerUp" */

PowerUp::PowerUp(PowerUpType type, Point position): _type(type), _position(position){
    // constructor implementation
}

PowerUpType PowerUp::getType() {
    return _type;
}

Point PowerUp::getPosition() {
    return _position;
}

int PowerUp::getNumberOfTypes() {
    return 3;
}
