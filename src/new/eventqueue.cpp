
#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <random>

#include "eventqueue.h"

/* Implementation of class "EventQueue" */

template <typename T>
int EventQueue<T>::getSize() {
    std::lock_guard<std::mutex> lock(_mutex);

    return _things.size();
}

template <typename T>
void EventQueue<T>::add(std::shared_ptr<T> thing, std::promise<void> &&promise) {
    std::lock_guard<std::mutex> lock(_mutex);

    _things.push_back(thing);
    _promises.push_back(std::move(promise));
}

template <typename T>
void EventQueue<T>::permitEntryToFirstInQueue() {
    std::lock_guard<std::mutex> lock(_mutex);

    // get entries from the front of both queues
    auto firstPromise = _promises.begin();
    auto firstThing = _things.begin();

    // fulfill promise and send signal back that permission to enter has been granted
    firstPromise->set_value();

    // remove front elements from both queues
    _things.erase(firstThing);
    _promises.erase(firstPromise);
}

// get the first one
template <typename T>
std::shared_ptr<T> EventQueue<T>::get() {
    std::lock_guard<std::mutex> lock(_mutex);
    
    if (_things.empty()) {
        return nullptr;
    }
    
    return _things.front();
}