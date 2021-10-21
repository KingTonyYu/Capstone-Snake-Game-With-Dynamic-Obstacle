#ifndef DYNAMIC_OBSTACLE_H_
#define DYNAMIC_OBSTACLE_H_

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <random>
#include <algorithm>

#include "snake.h"

struct Block
{
  int x;
  int y;
  int radius;
  Block() {};
  Block(int _x, int _y, int _radius=1) : x(_x), y(_y), radius(_radius) {}
};

class DynamicObstacle
{
private:
  enum class Direction : int { UP = 0, DOWN, LEFT, RIGHT };
  Block block_;
  int speed_;
  int grid_width_;
  int grid_height_;
  Direction direction_;
  bool stop_thread_;

  std::vector<std::thread> threads_;

public:
  DynamicObstacle() {};
  DynamicObstacle(const DynamicObstacle&) = delete;
  DynamicObstacle(DynamicObstacle&&) = default;
  ~DynamicObstacle();
  DynamicObstacle(std::size_t _grid_width, std::size_t _grid_height);
  void simulate();
  void movementCycle();
  void placeBlock();
  void updateBlock();
  bool isInBlock(const Block& block, int x, int y);
  Block getBlock() const;
};

#endif // DYNAMIC_OBSTACLE_H_