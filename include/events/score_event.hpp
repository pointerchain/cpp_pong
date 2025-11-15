// include/events/score.hpp

#pragma once

#include "components/pong.hpp"

struct ScoreEvent {
  PaddleSide scoring_paddle_side;
};