// src/game.cpp

#include "game.hpp"

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "factory.hpp"
#include "systems/ball_system.hpp"
#include "systems/border_check_system.hpp"
#include "systems/cleanup_system.hpp"
#include "systems/collision_system.hpp"
#include "systems/event_system.hpp"
#include "systems/paddle_movement_system.hpp"
#include "systems/physics_system.hpp"
#include "systems/render_system.hpp"
#include "systems/score_system.hpp"

Game::Game() {
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  const int x = (desktop.size.x - window_.getSize().x) / 2;
  const int y = (desktop.size.y - window_.getSize().y) / 2;
  window_.setPosition({x, y});

  registry_.ctx().emplace<sf::RenderWindow&>(window_);
  registry_.ctx().emplace<entt::dispatcher&>(dispatcher_);
}

void Game::Run() {
  PaddleMovementSystem paddle_movement_system(registry_, dispatcher_);
  ScoreSystem score_system(registry_, dispatcher_);

  Factory factory(window_, registry_);
  factory.SpawnPaddles();
  factory.SpawnBall();

  while (window_.isOpen()) {
    const auto dt = clock_.restart().asSeconds();

    EventSystem(registry_);

    BallSystem(registry_, dt);
    PhysicsSystem(registry_, dt);
    BorderCheckSystem(registry_);
    CollisionSystem(registry_);

    dispatcher_.update();

    RenderSystem(registry_);
    CleanupSystem(registry_);
  }
}