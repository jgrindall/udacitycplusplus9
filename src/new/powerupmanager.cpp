
#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <random>
#include <memory>

#include "powerupmanager.h"

//helper
int getRandomType() {
    int NUM_TYPES = 3; // SPEED, GHOST, SCORE. TODO - is there a better way to do this?
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> type_dist(0, NUM_TYPES - 1);
    return type_dist(gen);
}

int getRandomPosition(int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> pos_dist(0, max - 1);
    return pos_dist(gen);
}


/* Implementation of class "PowerUpManager" */

PowerUpManager::PowerUpManager(int grid_width, int grid_height) : grid_width(grid_width), grid_height(grid_height) {
    // constructor implementation
    _running = true;
    _spawnQueue = std::make_unique<EventQueue<PowerUp>>();
}

void PowerUpManager::start() {
    _running = true;
    _spawnThread = std::thread(&PowerUpManager::spawnThread, this);
}

void PowerUpManager::stop() {
    _running = false;
    if (_spawnThread.joinable()) {
        _spawnThread.join();
    }
}

void PowerUpManager::spawnThread() {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    while (_running) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        
        if (!_running){
            break;
        }
        
        // Create powerup with random type and position

        int intType = getRandomType();
        int x = getRandomPosition(grid_width);
        int y = getRandomPosition(grid_height);

        PowerUpType type = static_cast<PowerUpType>(intType);
        Point position = {
            x, 
            y
        };
    
        auto powerup = std::make_shared<PowerUp>(type, position);
        
        std::promise<void> promise;
        _spawnQueue->add(powerup, std::move(promise));
    }
}
