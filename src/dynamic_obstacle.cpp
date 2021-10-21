#include "dynamic_obstacle.h"

DynamicObstacle::DynamicObstacle(std::size_t _grid_width, std::size_t _grid_height)
  : grid_width_(static_cast<int>(_grid_width)),
    grid_height_(static_cast<int>(_grid_height)),
    speed_(1),
    direction_(Direction::UP)
{
  placeBlock();
}

DynamicObstacle::~DynamicObstacle()
{
  stop_thread_ = true;
  std::cout << "Destruct dynamic obstacle" << std::endl;
  std::for_each(threads_.begin(), threads_.end(), [](std::thread &t)
  {
    t.join();
  });
}

void DynamicObstacle::simulate()
{
  threads_.emplace_back(std::thread(&DynamicObstacle::movementCycle, this));
}

Block DynamicObstacle::getBlock() const
{
  return block_;
}

void DynamicObstacle::movementCycle()
{
  std::mt19937 eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist(0, 3);
  while (!stop_thread_)
  {
    direction_ = Direction(dist(eng));
    speed_ = dist(eng);
    updateBlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

}

void DynamicObstacle::updateBlock()
{
  switch (direction_) {
    case Direction::UP:
      block_.y -= speed_;
      break;

    case Direction::DOWN:
      block_.y += speed_;
      break;

    case Direction::LEFT:
      block_.x -= speed_;
      break;

    case Direction::RIGHT:
      block_.x += speed_;
      break;
  }
  block_.x = fmod(block_.x + grid_width_, grid_width_);
  block_.y = fmod(block_.y + grid_height_, grid_height_);
}

bool DynamicObstacle::isInBlock(const Block& block, int x, int y)
{
  for (int i = block.x - block.radius; i <= block.x + block.radius; i++)
  {
    for (int j = block.y - block.radius; j <= block.y + block.radius; j++)
    {
      if (x == i && y == j)
        return true;
    }
  }
  return false;
}

void DynamicObstacle::placeBlock()
{
  std::mt19937 eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist_w(0, grid_width_ - 1);
  std::uniform_int_distribution<int> dist_h(0, grid_height_ - 1);
  while (true) {
    int x = dist_w(eng);
    int y = dist_h(eng);
    Block block(x, y);

    // avoid snake init position
    if (!isInBlock(block, grid_width_ / 2, grid_height_ / 2))
    {
      block_ = std::move(block);
      return;
    }
  }

}