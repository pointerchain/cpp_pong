// include/game.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

class Game {
 public:
  Game();

  void Run();

 private:
  sf::RenderWindow window_{sf::VideoMode(sf::Vector2u(2500, 1400)), "C++ Pong",
                           sf::Style::Titlebar | sf::Style::Close};
  entt::registry registry_{};
  entt::dispatcher dispatcher_{};
  sf::Clock clock_{};
};