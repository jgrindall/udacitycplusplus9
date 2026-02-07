
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

* All new functionality is in the/src/new/ folder.


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


