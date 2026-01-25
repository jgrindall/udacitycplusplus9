
#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <vector>
#include <future>
#include <mutex>
#include <memory>


template <typename T>
class EventQueue
{
public:
    int getSize();
    void add(std::shared_ptr<T> thing, std::promise<void> &&promise);
    void permitEntryToFirstInQueue();

private:
    
    // list of all things waiting to enter this event queue
    std::vector<std::shared_ptr<T>> _things;

    // list of associated promises
    std::vector<std::promise<void>> _promises;

    // mutex for thread safety
    std::mutex _mutex;
};

#include "eventqueue.cpp"

#endif