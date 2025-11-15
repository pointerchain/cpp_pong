// include/components/pong.hpp

#pragma once

enum class PaddleSide { Left, Right };

struct Paddle {
  const PaddleSide paddle_side;
};

struct Ball {};