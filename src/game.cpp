#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();

  //// FP.1b : Add dynamic obstacle
  // dynamic_obstacle_ = DynamicObstacle(grid_width, grid_height);
  for (int i = 0; i < num_obstacle_; i++)
  {
    // DynamicObstacle d(grid_width, grid_height);
    dynamic_obstacles_.emplace_back(grid_width, grid_height);
  }
  //// END
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  std::for_each(dynamic_obstacles_.begin(), dynamic_obstacles_.end(), [](auto& ob) {
    ob.simulate();
  });

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    checkObstacle();
    renderer.Render(snake, food, dynamic_obstacles_);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }

//// FP.2b : Detect whether the head hit the obstacles or not.
void Game::checkObstacle()
{
  for (const auto& obstacle : dynamic_obstacles_) {
    Block ob_block = obstacle.getBlock();
    for (int x = ob_block.x - ob_block.radius; x <= ob_block.x + ob_block.radius; x++) {
      for (int y = ob_block.y - ob_block.radius; y <= ob_block.y + ob_block.radius; y++) {
        if (x == static_cast<int>(snake.head_x) && y == static_cast<int>(snake.head_y)) {
          snake.alive = false;
          return;
        }
      }
    }
  }
}

////