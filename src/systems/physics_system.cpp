// src/systems/physics_system.cpp

#include "systems/physics_system.hpp"

#include "components/physics.hpp"

void PhysicsSystem(entt::registry &registry, const float dt) {
  for (auto [entity, position, velocity] : registry.view<Position, const Velocity>().each()) {
    position.x += velocity.dx * dt;
    position.y += velocity.dy * dt;
  }
}