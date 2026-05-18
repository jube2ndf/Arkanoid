#pragma once
#include "GameObject.h"
#include "AppSettings.h"
#include "PaddleState.h"

namespace Arkanoid::Game {
	class Paddle: public GameObject
	{
	public:
		Paddle();
		Paddle(float width, float hieght, sf::Vector2f position);

		// Унаследовано через GameObject
		void draw(sf::RenderWindow& window) override;
		sf::FloatRect getBounds() const override;
		void update(float dt) override;
		ObjectType getType() const override;
		sf::Vector2f getPosition() override;
		void setPosition(sf::Vector2f newP) override;

		void setState(const PaddleState& state);

	private:
		PaddleState _state;

		sf::RectangleShape _paddle;
		float _speed;
	};
}