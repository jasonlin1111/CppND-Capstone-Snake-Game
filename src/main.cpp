#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  int p1_score = 0, p2_score = 0;

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  p1_score = game.GetScore();
  p2_score = game.GetP2Score();
  std::cout << "P1 Score: " << p1_score << "\n";
  std::cout << "P2 Score: " << p2_score << "\n";
  if (p1_score > p2_score) {
	std::cout << "P1 Won" << "\n";
  } else if (p1_score < p2_score) {
	std::cout << "P2 Won" << "\n";
  } else {
	std::cout << "Game was tied" << "\n";
  }
  return 0;
}
