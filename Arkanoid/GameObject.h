#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectType.h"

namespace Arkanoid::Game {
	class GameObject {
	public:
		virtual ~GameObject() = default;

		virtual void update(float dt) {}
		virtual void onCollision(GameObject& other) {}
		virtual void drow(sf::RenderWindow& window) = 0;
		virtual ObjectType getType() const = 0;

		virtual sf::FloatRect getBounds() const = 0;
	};
}