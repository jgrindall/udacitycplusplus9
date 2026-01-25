
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
    void start();
    void stop();
    void check();

private:

    int grid_width;
    int grid_height;
    bool _running;

    int MAX_ALLOWED_POWERUPS = 3;

    // the ones on the screen
    std::vector<std::shared_ptr<PowerUp>> _powerups;

    // queue for spawning powerups
    std::unique_ptr<EventQueue<PowerUp>> _spawnQueue;

    // thread for spawning powerups
    std::thread _spawnThread;

    void spawnThread();
};
#endif