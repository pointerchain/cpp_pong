// include/components/pong.hpp

#pragma once

#include "config.hpp"

enum class PaddleSide { Left, Right };
enum class BallState { Spawning, Active };

struct Paddle {
  const PaddleSide paddle_side;
};

struct Ball {
  BallState ball_state{BallState::Spawning};
  float state_timer{Config::Ball::kSpawnTimer};
};

struct SpawnBallRequest {};