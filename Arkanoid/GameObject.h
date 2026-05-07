#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectType.h"

namespace Arkanoid::Game {
	class GameObject {
	public:
		virtual ~GameObject() = default;

		virtual void update(float dt) {}
		virtual void onCollision(GameObject& other) {}
		virtual void draw(sf::RenderWindow& window) = 0;
		virtual ObjectType getType() const = 0;

		virtual sf::Vector2f getPosition() = 0;
		virtual void setPosition(sf::Vector2f position) = 0;
		virtual sf::FloatRect getBounds() const = 0;
	};
}