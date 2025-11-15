// src/factory.cpp

#include "factory.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include "components/drawable.hpp"
#include "components/geometry.hpp"
#include "components/physics.hpp"
#include "components/pong.hpp"

Factory::Factory(const sf::RenderWindow &window, entt::registry &registry)
    : window_(window), registry_(registry) {}

void Factory::SpawnPaddles() {
  const auto left_paddle_entity = registry_.create();
  registry_.emplace<Paddle>(left_paddle_entity, PaddleSide::Left);
  registry_.emplace<Drawable>(left_paddle_entity);
  registry_.emplace<Size>(left_paddle_entity, 25, 200);
  registry_.emplace<Position>(left_paddle_entity, 150, window_.getSize().y / 2);
  registry_.emplace<Velocity>(left_paddle_entity, 0, 0);

  const auto right_paddle_entity = registry_.create();
  registry_.emplace<Paddle>(right_paddle_entity, PaddleSide::Right);
  registry_.emplace<Drawable>(right_paddle_entity);
  registry_.emplace<Size>(right_paddle_entity, 25, 200);
  registry_.emplace<Position>(right_paddle_entity, window_.getSize().x - 150,
                              window_.getSize().y / 2);
  registry_.emplace<Velocity>(right_paddle_entity, 0, 0);
}

void Factory::SpawnBall() {
  const auto ball_entity = registry_.create();
  registry_.emplace<Ball>(ball_entity);
  registry_.emplace<Drawable>(ball_entity);
  registry_.emplace<Radius>(ball_entity, 25);
  registry_.emplace<Position>(ball_entity, window_.getSize().x / 2, window_.getSize().y / 2);
  registry_.emplace<Velocity>(ball_entity, 0, 0);
}