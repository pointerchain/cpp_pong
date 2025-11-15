// src/systems/border_check_system.cpp

#include "systems/border_check_system.hpp"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <optional>

#include "components/geometry.hpp"
#include "components/physics.hpp"
#include "components/pong.hpp"
#include "components/to_destroy.hpp"
#include "events/score_event.hpp"

void BorderCheckSystem(entt::registry& registry) {
  auto& window = registry.ctx().get<sf::RenderWindow&>();
  auto& dispatcher = registry.ctx().get<entt::dispatcher&>();

  for (auto [entity, position, velocity] : registry.view<Position, Velocity>().each()) {
    const bool is_ball = registry.all_of<Ball>(entity);

    float half_width{};
    float half_height{};

    if (const auto* radius = registry.try_get<const Radius>(entity)) {
      half_width = radius->r;
      half_height = radius->r;
    } else if (const auto* size = registry.try_get<const Size>(entity)) {
      half_width = size->x / 2.0f;
      half_height = size->y / 2.0f;
    }

    std::optional<PaddleSide> scoring_paddle_side;

    if (position.x - half_width < 0) {
      position.x = half_width;
      if (is_ball) {
        scoring_paddle_side = PaddleSide::Right;
      }
    } else if (position.x + half_width > window.getSize().x) {
      position.x = window.getSize().x - half_width;
      if (is_ball) {
        scoring_paddle_side = PaddleSide::Left;
      }
    }

    if (position.y - half_height < 0) {
      position.y = half_height;
      if (is_ball) {
        velocity.dy = std::abs(velocity.dy);
      }
    } else if (position.y + half_height > window.getSize().y) {
      position.y = window.getSize().y - half_height;
      if (is_ball) {
        velocity.dy = -std::abs(velocity.dy);
      }
    }

    if (scoring_paddle_side) {
      dispatcher.enqueue<ScoreEvent>({*scoring_paddle_side});
      registry.emplace<ToDestroy>(entity);
    }
  }
}