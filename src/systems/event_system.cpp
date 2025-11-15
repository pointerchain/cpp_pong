// src/systems/event_system.cpp

#include "systems/event_system.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "components/pong.hpp"
#include "events/input_event.hpp"

void EventSystem(entt::registry& registry) {
  auto& window = registry.ctx().get<sf::RenderWindow&>();
  auto& dispatcher = registry.ctx().get<entt::dispatcher&>();

  const auto onClose = [&](const sf::Event::Closed&) { window.close(); };
  const auto keyPress = [&](const sf::Event::KeyPressed& key_pressed) {
    if (key_pressed.scancode == sf::Keyboard::Scancode::W) {
      dispatcher.enqueue<PaddleMoveEvent>({PaddleSide::Left, -1});
    } else if (key_pressed.scancode == sf::Keyboard::Scancode::S) {
      dispatcher.enqueue<PaddleMoveEvent>({PaddleSide::Left, 1});
    }
  };
  const auto keyRelease = [&](const sf::Event::KeyReleased& key_released) {
    if (key_released.scancode == sf::Keyboard::Scancode::W) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
        dispatcher.enqueue<PaddleMoveEvent>({PaddleSide::Left, 1});
      } else {
        dispatcher.enqueue<PaddleMoveEvent>({PaddleSide::Left, 0});
      }
    } else if (key_released.scancode == sf::Keyboard::Scancode::S) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
        dispatcher.enqueue<PaddleMoveEvent>({PaddleSide::Left, -1});
      } else {
        dispatcher.enqueue<PaddleMoveEvent>({PaddleSide::Left, 0});
      }
    }
  };

  window.handleEvents(onClose, keyPress, keyRelease);
}