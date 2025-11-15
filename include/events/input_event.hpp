// include/events/input_event.hpp

#pragma once

#include "components/pong.hpp"
struct PaddleMoveEvent {
  PaddleSide paddle_side;
  float direction;
};