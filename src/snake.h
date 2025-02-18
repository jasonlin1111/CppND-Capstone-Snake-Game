#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height, float head_x, float head_y)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(head_x),
        head_y(head_y) {}

  void Update(const Snake &theOtherSnake);

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell, const Snake &theOtherSnake);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
