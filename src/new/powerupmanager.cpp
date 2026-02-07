
#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <random>
#include <memory>
#include <algorithm>

#include "powerupmanager.h"
#include "poweruptypes.h"
#include "../snake.h"

//helpers
int getRandomType() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> type_dist(0, PowerUp::getNumberOfTypes() - 1);
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

PowerUpManager::~PowerUpManager() {
    stop();
}

void PowerUpManager::start() {
    _running = true;

    // start the spawn thread
    _spawnThread = std::thread(&PowerUpManager::spawnThread, this);
}

void PowerUpManager::remove(std::shared_ptr<PowerUp> powerup) {
    // remove powerup from the list
    auto it = std::find(_powerups.begin(), _powerups.end(), powerup);
    if (it != _powerups.end()) {
        // foiund it
        _powerups.erase(it);
    }
}

void PowerUpManager::apply(std::shared_ptr<PowerUp> powerup, Snake& snake, int& score) {
    // apply the effect of the powerup
    if(!powerup) {
        return;
    }
    PowerUpType type = powerup->getType();
    // implement effects based on type
    if(type == PowerUpType::SLOW_DOWN) {
        snake.speed = std::max(0.02f, snake.speed - 0.05f);
    }
    else if(type == PowerUpType::GHOST_MODE) {
        // not done yet!!
    }
    else if(type == PowerUpType::EXTRA_SCORE) {
        score += 5;
    }
}

void PowerUpManager::check() {
    if (_powerups.size() < MAX_ALLOWED_POWERUPS && _spawnQueue->getSize() > 0) {
        auto powerup = _spawnQueue->get();
        _spawnQueue->permitEntryToFirstInQueue();
        _powerups.push_back(powerup);
    }
}

std::vector<std::shared_ptr<PowerUp>> PowerUpManager::getPowerUps() {
    return _powerups;
}

void PowerUpManager::stop() {
    _running = false;
    if (_spawnThread.joinable()) {
        _spawnThread.join();
    }
}

/**
 * Runs in a separate thread to spawn powerups at regular intervals.
 */
void PowerUpManager::spawnThread() {

    std::cout << "Spawn thread started." << std::endl;

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

        std::cout << "Spawned powerup of type " << intType << " at position (" << x << ", " << y << ")." << std::endl;
    }
}
