// game.cpp

#include "game.hpp"

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "components/drawable.hpp"
#include "components/geometry.hpp"
#include "components/physics.hpp"
#include "components/pong.hpp"
#include "systems/border_check_system.hpp"
#include "systems/cleanup_system.hpp"
#include "systems/event_system.hpp"
#include "systems/physics_system.hpp"
#include "systems/render_system.hpp"

void Game::Run() {
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  const int x = (desktop.size.x - window_.getSize().x) / 2;
  const int y = (desktop.size.y - window_.getSize().y) / 2;
  window_.setPosition({x, y});

  sf::Clock clock{};

  registry_.ctx().emplace<sf::RenderWindow&>(window_);
  registry_.ctx().emplace<entt::dispatcher&>(dispatcher_);

  const auto ball_entity = registry_.create();
  registry_.emplace<Ball>(ball_entity);
  registry_.emplace<Drawable>(ball_entity);
  registry_.emplace<Radius>(ball_entity, 25);
  registry_.emplace<Position>(ball_entity, 100, 100);
  registry_.emplace<Velocity>(ball_entity, 1000, 1000);

  const auto left_paddle_entity = registry_.create();
  registry_.emplace<Paddle>(left_paddle_entity);
  registry_.emplace<Drawable>(left_paddle_entity);
  registry_.emplace<Size>(left_paddle_entity, 25, 200);
  registry_.emplace<Position>(left_paddle_entity, 150, window_.getSize().y / 2);
  registry_.emplace<Velocity>(left_paddle_entity, 0, 0);

  const auto right_paddle_entity = registry_.create();
  registry_.emplace<Paddle>(right_paddle_entity);
  registry_.emplace<Drawable>(right_paddle_entity);
  registry_.emplace<Size>(right_paddle_entity, 25, 200);
  registry_.emplace<Position>(right_paddle_entity, window_.getSize().x - 150,
                              window_.getSize().y / 2);
  registry_.emplace<Velocity>(right_paddle_entity, 0, 0);

  while (window_.isOpen()) {
    const auto dt = clock.restart().asSeconds();

    EventSystem(registry_);
    PhysicsSystem(registry_, dt);
    BorderCheckSystem(registry_);
    RenderSystem(registry_);
    CleanupSystem(registry_);
  }
}