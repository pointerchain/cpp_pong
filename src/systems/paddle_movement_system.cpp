// src/systems/paddle_movement_system.cpp

#include "systems/paddle_movement_system.hpp"

#include <entt/entt.hpp>

#include "components/physics.hpp"
#include "components/pong.hpp"
#include "config.hpp"
#include "events/input_event.hpp"

PaddleMovementSystem::PaddleMovementSystem(entt::registry& registry, entt::dispatcher& dispatcher)
    : registry_(registry) {
  dispatcher.sink<PaddleMoveEvent>().connect<&PaddleMovementSystem::OnPaddleMove>(this);
}

void PaddleMovementSystem::OnPaddleMove(const PaddleMoveEvent& paddle_move_event) {
  for (auto [entity, paddle, velocity] : registry_.view<Paddle, Velocity>().each()) {
    if (paddle.paddle_side != paddle_move_event.paddle_side) {
      continue;
    }

    velocity.dy = paddle_move_event.direction * Config::Paddle::kSpeed;
  }
}
