// src/systems/ball_system.cpp

#include "systems/ball_system.hpp"

#include <cmath>

#include "components/physics.hpp"
#include "components/pong.hpp"
#include "config.hpp"

void BallSystem(entt::registry &registry, const float dt) {
  for (auto [entity, ball, velocity] : registry.view<Ball, Velocity>().each()) {
    switch (ball.ball_state) {
      case BallState::Spawning: {
        if (ball.state_timer <= 0) {
          velocity.dx = Config::Ball::kInitialSpeed;
          velocity.dy = Config::Ball::kInitialSpeed;

          ball.ball_state = BallState::Active;
          ball.state_timer = 0;
        } else {
          ball.state_timer -= dt;
        }

        break;
      }
      case BallState::Active: {
        const auto acceleration = Config::Ball::kAccelerationSpeed * dt;

        velocity.dx += std::copysign(acceleration, velocity.dx);
        velocity.dy += std::copysign(acceleration, velocity.dy);

        break;
      }
    }
  }
}