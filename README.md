# CPPND: Capstone Snake Game with Dynamic Obstacles

This is a motified version for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="window.png"/>

In this game, the snake need to eat food and avoid the randomly moving obstacles as well. To achieve this, a `DynamicObstacle` class is created and contained in the files: `dynamic_obstacle.h` and `dynamic_obstacle.cpp` under `/src`. Each `DynamicObstacle` defines one dynamic obstacle that once the `simulate()` function is called, it will pick the direction and speed randomly for next movement. In the game, multiple dyanmic obstacles are defined and run parallel.

Apart from the `dynamic_obstacle.h` and `dynamic_obstacle.cpp`, all the changes in original files are marked as `FP`, they are:

1. `FP.1a` changes in `game.h` to add dynamic obstacle. Others that do the same thing are: `FP.1b`(`game.cpp`), `FP.1c`(`render.cpp`), `FP.1d`(`render.h`).
2. `FP.2a` and `FP.2b` are changes in game.h and game.cpp to detect whether the snake head hit the obstacle. If yes, the game is terminated as well.


## Dependencies for Running Locally
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

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.




## Rubric

__README (All Rubric Points REQUIRED)__

|DONE | CRITERIA | MEETS SPECIFICATIONS| WHERE |
|:-- | :-- | :--| :-- |
| Yes | A README with instructions is included with the project |The README is included with the project and has instructions for building/running the project. If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions. You can submit your writeup as markdown or pdf.| |
| Yes | The README indicates which project is chosen. | The README describes the project you have built. The README also indicates the file and class structure, along with the expected behavior or output of the program. | |
| Yes| The README includes information about each rubric point addressed. | The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed. | |

__Compiling and Testing (All Rubric Points REQUIRED)__

|DONE | CRITERIA | MEETS SPECIFICATIONS| WHERE |
|:-- | :-- | :--| :-- |
| Yes | The submission must compile and run. | The project code must compile and run without errors. We strongly recommend using cmake and make, as provided in the starter repos. If you choose another build system, the code must compile on any reviewer platform. |

__Loops, Functions, I/O__

|DONE | CRITERIA | MEETS SPECIFICATIONS| WHERE |
|:-- | :-- | :--| :-- |
| Yes | The project demonstrates an understanding of C++ functions and control structures.| A variety of control structures are used in the project. The project code is clearly organized into functions.| dynamic_obstacle.cpp |
|  | The project reads data from a file and process the data, or the program writes data to a file. | The project reads data from an external file or writes data to a file as part of the necessary operation of the program.| reads image frame in main.cpp  |
|  | The project accepts user input and processes the input.|The project accepts input from a user as part of the necessary operation of the program.|  |

__Object Oriented Programming__

|DONE | CRITERIA | MEETS SPECIFICATIONS| WHERE |
|:-- | :-- | :--| :-- |
| Yes | The project uses Object Oriented Programming techniques. | The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks. | dynamic_obstacle.h and dynamic_obstacle.cpp |
| Yes | Classes use appropriate access specifiers for class members. | All class data members are explicitly specified as public, protected, or private.| dynamic_obstacle.h and dynamic_obstacle.cpp |
| Yes| Class constructors utilize member initialization lists. | All class members that are set to argument values are initialized through member initialization lists.| dynamic_obstacle.cpp |
| Yes | Classes abstract implementation details from their interfaces. | All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.| dynamic_obstacle.h and dynamic_obstacle.cpp |
| Yes | Classes encapsulate behavior. | Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.| dynamic_obstacle.h and dynamic_obstacle.cpp |
| | Classes follow an appropriate inheritance hierarchy. | Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.|  |
|  | Overloaded functions allow the same function to operate on different parameters. |  |
|  | Derived class functions override virtual base class functions. |One member function in an inherited class overrides a virtual base class member function.| |
|  | Templates generalize functions in the project. | One function is declared with a template that allows it to accept a generic parameter.| |

__Memory Management__

|DONE | CRITERIA | MEETS SPECIFICATIONS| WHERE |
|:-- | :-- | :--| :-- |
| Yes | The project makes use of references in function declarations. | At least two variables are defined as references, or two functions use pass-by-reference in the project code.| dynamic_obstacle.cpp |
| Yes | The project uses destructors appropriately. | At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor. | dynamic_obstacle.cpp |
|  | The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.| |
|  | The project follows the Rule of 5. | For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined.|  |
| Yes | The project uses move semantics to move data, instead of copying it, where possible. | For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object. | dynamic_obstacle.cpp line 95  |
|  | The project uses smart pointers instead of raw pointers. | The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.| |

__Concurrency__

|DONE | CRITERIA | MEETS SPECIFICATIONS| WHERE |
|:-- | :-- | :--| :-- |
| Yes| The project uses multithreading. | The project uses multiple threads in the execution.| dynamic_obstacle.cpp |
|  | A promise and future is used in the project. | A promise and future is used to pass data from a worker thread to a parent thread in the project code.| |
|  | A mutex or lock is used in the project. | A mutex or lock (e.g. std::lock_guard or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code.| used in Buffer extensively |
|  | A condition variable is used in the project. | A std::condition_variable is used in the project code to synchronize thread execution.| |


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
