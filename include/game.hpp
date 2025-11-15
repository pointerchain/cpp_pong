// include/game.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "config.hpp"

class Game {
 public:
  Game();

  void Run();

 private:
  sf::RenderWindow window_{
      sf::VideoMode(sf::Vector2u(Config::Window::kWidth, Config::Window::kHeight)), "C++ Pong",
      sf::Style::Titlebar | sf::Style::Close};
  entt::registry registry_{};
  entt::dispatcher dispatcher_{};
  sf::Clock clock_{};
};