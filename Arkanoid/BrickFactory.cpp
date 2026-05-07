#include "BrickFactory.h"
#include "Brick.h"
#include "DurableBrick.h"

Arkanoid::Game::BrickFactory::BrickFactory(sf::Vector2f size)
{
	for (int i = 0; i < MAX_BRICK_HITS; i++) {
		this->_colors.push_back(this->getColorForHits(i, MAX_BRICK_HITS));
	}
	this->_size = size;
}

std::unique_ptr<Arkanoid::Game::Brick> Arkanoid::Game::BrickFactory::create(BrickType type, sf::Vector2f position)
{
	switch (type)
	{
	case Arkanoid::Game::BrickType::NORMAL:
		return std::make_unique<Brick>(position, this->_size);
	case Arkanoid::Game::BrickType::STRONG_2:
		return std::make_unique<DurableBrick>(
			std::vector<sf::Color>(this->_colors.begin(), this->_colors.begin() + 1),
			position, 
			this->_size
		);
	case Arkanoid::Game::BrickType::STRONG_3:
		return std::make_unique<DurableBrick>(
			std::vector<sf::Color>(this->_colors.begin(), this->_colors.begin() + 2),
			position,
			this->_size
		);
	case Arkanoid::Game::BrickType::RANDOM:
		return std::make_unique<DurableBrick>(
			std::vector<sf::Color>(this->_colors.begin(), this->_colors.begin() + (rand() % 10 + 1)),
			position,
			this->_size
		);
	default:
		return std::make_unique<Brick>(position, this->_size);
	}
}
