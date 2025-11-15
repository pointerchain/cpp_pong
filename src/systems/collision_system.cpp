// src/systems/border_check_system.cpp

#include "systems/collision_system.hpp"

#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "components/geometry.hpp"
#include "components/physics.hpp"
#include "components/pong.hpp"

namespace {

bool IsBallIntersectingWithPaddle(const Position circle_pos, const Radius circle_radius,
                                  const Position rect_pos, const Size rect_size) {
  const auto half_w = rect_size.x / 2;
  const auto half_h = rect_size.y / 2;

  const auto delta_x = std::abs(circle_pos.x - rect_pos.x);
  const auto delta_y = std::abs(circle_pos.y - rect_pos.y);

  const auto dist_x = std::max(0.f, delta_x - half_w);
  const auto dist_y = std::max(0.f, delta_y - half_h);

  const auto distance_squared = dist_x * dist_x + dist_y * dist_y;
  const auto radius_squared = circle_radius.r * circle_radius.r;

  return distance_squared <= radius_squared;
}

}  // namespace

void CollisionSystem(entt::registry& registry) {
  auto& window = registry.ctx().get<sf::RenderWindow&>();

  for (auto [ball_entity, ball, ball_position, ball_velocity, ball_radius] :
       registry.view<Ball, Position, Velocity, const Radius>().each()) {
    for (auto [paddle_entity, paddle, paddle_position, paddle_velocity, paddle_size] :
         registry.view<const Paddle, const Position, const Velocity, const Size>().each()) {
      if (!IsBallIntersectingWithPaddle(ball_position, ball_radius, paddle_position, paddle_size)) {
        continue;
      }

      if (paddle.paddle_side == PaddleSide::Left) {
        ball_velocity.dx = std::abs(ball_velocity.dx);
      } else {
        ball_velocity.dx = -std::abs(ball_velocity.dx);
      }
    }
  }
}