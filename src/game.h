#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <algorithm>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "dynamic_obstacle.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();

  //// FP.1a : Add dynamic obstacle.
  int num_obstacle_ = 3;
  std::vector<DynamicObstacle> dynamic_obstacles_;
  //// END

  //// FP.2a : Detect whether the head hit the obstacles or not.
  void checkObstacle();
  //// END

};

#endif