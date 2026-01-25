
#ifndef POWERUPMANAGER_H
#define POWERUPMANAGER_H

#include <vector>
#include <future>
#include <mutex>
#include <memory>

#include "powerup.h"
#include "eventqueue.h"

class PowerUpManager
{
public:
    PowerUpManager(int grid_width, int grid_height);
    
    // start spawning powerups
    void start();

    // when the game ends we stop
    void stop();

    // check if main loop can add a new powerup from the spawn queue
    void check();

    // snake ate it
    void remove(std::shared_ptr<PowerUp> powerup);

    // what does it do?
    void apply(std::shared_ptr<PowerUp> powerup);

    // get the current powerups on screen
    std::vector<std::shared_ptr<PowerUp>> getPowerUps();

private:

    int grid_width;
    int grid_height;
    bool _running;

    // maximum allowed powerups on screen, so it doesn't fil up with stuff
    int MAX_ALLOWED_POWERUPS = 3;

    // the ones on the screen now
    std::vector<std::shared_ptr<PowerUp>> _powerups;

    // queue for spawning powerups
    std::unique_ptr<EventQueue<PowerUp>> _spawnQueue;

    // thread for spawning powerups
    std::thread _spawnThread;

    void spawnThread();
};
#endif