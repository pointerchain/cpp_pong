// event_system.cpp

#include "systems/event_system.hpp"

#include <SFML/Graphics.hpp>
#include "events/move_event.hpp"

void EventSystem(entt::registry& registry) {
  auto& window = registry.ctx().get<sf::RenderWindow&>();
  auto& dispatcher = registry.ctx().get<entt::dispatcher&>();

  const auto onClose = [&](const sf::Event::Closed&) { window.close(); };
  const auto keyPress = [&](const sf::Event::KeyPressed&) {
    dispatcher.enqueue<MoveEvent>({
      
    })
  };

  window.handleEvents(onClose);
}