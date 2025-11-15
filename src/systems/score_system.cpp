// src/systems/score_system.cpp

#include "systems/score_system.hpp"

#include <entt/entt.hpp>
#include <print>

#include "components/pong.hpp"
#include "events/score_event.hpp"
#include "factory.hpp"

ScoreSystem::ScoreSystem(entt::registry& registry, entt::dispatcher& dispatcher)
    : registry_(registry) {
  dispatcher.sink<ScoreEvent>().connect<&ScoreSystem::OnScore>(this);
}

void ScoreSystem::OnScore(const ScoreEvent& score_event) {
  auto& window = registry_.ctx().get<sf::RenderWindow&>();

  if (score_event.scoring_paddle_side == PaddleSide::Left) {
    ++left_score_;
  } else {
    ++right_score_;
  }

  std::println("{} | {}", left_score_, right_score_);

  Factory factory(window, registry_);
  factory.SpawnBall();
}
