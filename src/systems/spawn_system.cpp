// src/systems/spawn_system.cpp

#include "systems/spawn_system.hpp"

#include <SFML/Graphics.hpp>

#include "components/pong.hpp"
#include "components/to_destroy.hpp"
#include "factory.hpp"

void SpawnSystem(entt::registry& registry) {
  auto& window = registry.ctx().get<sf::RenderWindow&>();
  Factory factory(window, registry);

  for (const auto& entity : registry.view<SpawnBallRequest>()) {
    factory.SpawnBall();

    registry.emplace<ToDestroy>(entity);
  }
}