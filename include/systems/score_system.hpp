// include/systems/score_system.hpp

#pragma once

#include <entt/entt.hpp>

#include "events/score_event.hpp"

struct ScoreSystem {
  int left_score_{};
  int right_score_{};

  entt::registry& registry_;

  ScoreSystem(entt::registry& registry, entt::dispatcher& dispatcher);

  void OnScore(const ScoreEvent& score_event);
};