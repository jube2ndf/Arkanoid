#pragma once
#include "GameObject.h"
namespace Arkanoid::Game {
	class Paddle: public GameObject
	{
	public:
		Paddle(float width, float hieght, sf::Vector2f position);

		// Унаследовано через GameObject
		void drow(sf::RenderWindow& window) override;
		sf::FloatRect getBounds() const override;
		void update(float dt) override;
	private:
		sf::RectangleShape _paddle;
		float _speed = 200.0f;
	};
}