// include/systems/paddle_movement_system.hpp

#pragma once

#include <entt/entt.hpp>

#include "events/input_event.hpp"

struct PaddleMovementSystem {
  entt::registry& registry_;

  PaddleMovementSystem(entt::registry& registry, entt::dispatcher& dispatcher);

  void OnPaddleMove(const PaddleMoveEvent& paddle_move_event);
};