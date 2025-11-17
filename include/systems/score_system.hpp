// include/systems/score_system.hpp

#pragma once

#include <entt/entt.hpp>

#include "components/pong.hpp"
#include "events/score_event.hpp"

struct ScoreSystem {
  entt::registry& registry_;
  GameScore& game_score_;

  ScoreSystem(entt::registry& registry, entt::dispatcher& dispatcher, GameScore& game_score);

  void OnScore(const ScoreEvent& score_event);
};