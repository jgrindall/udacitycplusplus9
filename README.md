
# Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

# Basic Build Instructions

1. Clone this repo.

2. Install dependencies

sudo apt-get install libsdl2-gfx-dev
Used for drawing circles

sudo apt-get install libsdl2-ttf-dev
Used for rendering text

3. Make a build directory in the top level directory: `mkdir build && cd build`
4. Compile: `cmake .. && make`
5. Run it: `./SnakeGame`.



# New features:

All new functionality is in the/src/new/ folder.


* 1. Generic class EventQueue

_things - Queue of items

_promises - Promises that get fulfilled when items are allowed through

_mutex - Ensures thread-safe access





* 2. Power up manager

Has an instance of an EventQueue (_spawnQueue)

Waits using the check method.

Three different kinds of powerups (slow down the snake, ghost mode, score boost)

These spawn each 5 seconds




* 3. Render the score at the top left.




# Rubric points:

* The project demonstrates an understanding of C++ functions and control structures.

See powerupmanager.cpp and eventqueue.cpp





* The project uses data structures and immutable variables.

See

powerupmanager.h:L47 - std::vector<std::shared_ptr<PowerUp>> _powerups
eventqueue.h:L28 - std::vector<std::shared_ptr<T>> _things
eventqueue.h:L31 - std::vector<std::promise<void>> _promises
powerupmanager.h:L45 - const int MAX_ALLOWED_POWERUPS = 3






* One or more classes are added to the project with appropriate access specifiers for class members.
* Classes are organized with attributes to hold data and methods to perform tasks.

See 
powerupmanager.cpp/h, eventqueue.cpp/h, powerup.cpp/h


* Class constructors utilize member initialization lists.

powerupmanager.cpp:L32

* All class data members are explicitly specified as public, protected, or private.

See 
powerupmanager.cpp/h, eventqueue.cpp/h, powerup.cpp/h



* Templates generalize functions or classes in the project.


See 
eventqueue.cpp/h - template <typename T> class EventQueue


* Classes abstract implementation details from their interfaces.

See 
powerupmanager.cpp/h, eventqueue.cpp/h



* The project makes use of references in function declarations.

See PowerUpManager::apply



* The project uses destructors appropriately.

See ~PowerUpManager()



* The project uses move semantics to move data instead of copying it, where possible.

See

eventqueue.cppL24 - _promises.push_back(std::move(promise))
powerupmanager.cppL127 - _spawnQueue->add(powerup, std::move(promise))



* The project uses smart pointers instead of raw pointers.

See
powerupmanager.hL50 - std::unique_ptr<EventQueue<PowerUp>> _spawnQueue
powerupmanager.cppL34 - std::make_unique<EventQueue<PowerUp>>()


* The project uses multithreading.

See eventqueue.cpp and powerupmanager.cpp




* A promise and future is used in the project.

See eventqueue.cpp


* A mutex or lock is used in the project.

See

eventqueue.cppL14 - Protects queue access in getSize()
eventqueue.cppL21 - Protects queue access in add()
eventqueue.cppL29 - Protects queue access in permitEntryToFirstInQueue()
