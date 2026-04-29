#pragma once
#include "GameObject.h"
#include "AppSettings.h"

namespace Arkanoid::Game {
	class Paddle: public GameObject
	{
	public:
		Paddle(float width, float hieght, sf::Vector2f position);

		sf::Vector2f getPosition();
		
		void setPosition(sf::Vector2f newP);
		
		// Унаследовано через GameObject
		void drow(sf::RenderWindow& window) override;
		sf::FloatRect getBounds() const override;
		void update(float dt) override;
		ObjectType getType() const override;
		
	private:
		sf::RectangleShape _paddle;
		float _speed = Arkanoid::App::Settings::GAME_PADDLE_SPEED;
	};
}