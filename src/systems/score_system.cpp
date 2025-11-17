// src/systems/score_system.cpp

#include "systems/score_system.hpp"

#include <entt/entt.hpp>

#include "components/pong.hpp"
#include "events/score_event.hpp"

ScoreSystem::ScoreSystem(entt::registry& registry, entt::dispatcher& dispatcher,
                         GameScore& game_score)
    : registry_(registry), game_score_(game_score) {
  dispatcher.sink<ScoreEvent>().connect<&ScoreSystem::OnScore>(this);
}

void ScoreSystem::OnScore(const ScoreEvent& score_event) {
  if (score_event.scoring_paddle_side == PaddleSide::Left) {
    ++game_score_.left;
  } else {
    ++game_score_.right;
  }

  registry_.emplace<SpawnBallRequest>(registry_.create());
}
