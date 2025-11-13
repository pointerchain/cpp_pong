// game.cpp

#include "game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <entt/entt.hpp>

#include "systems/cleanup_system.hpp"

void Game::Run() {
  while (window_.isOpen()) {
    while (const auto event = window_.pollEvent()) {
      const auto onClose = [&](const sf::Event::Closed) { window_.close(); };

      window_.handleEvents(onClose);
    }

    window_.clear();

    window_.display();

    CleanupSystem(registry_);
  }
}