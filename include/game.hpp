// game.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

class Game {
 public:
  void Run();

 private:
  sf::RenderWindow window_{sf::VideoMode(sf::Vector2u(500, 1000)), "C++ Pong"};
  entt::registry registry_{};
};