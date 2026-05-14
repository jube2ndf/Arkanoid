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
	if (type == Arkanoid::Game::BrickType::RANDOM) {
		type = static_cast<BrickType>(rand() % static_cast<int>(BrickType::RANDOM) + 1);
	}
	BrickData dto = {
		position.x,
		position.y,
		1,
		static_cast<int>(type)
	};
	switch (type)
	{
	case Arkanoid::Game::BrickType::NORMAL:
		return createNormal(dto);
	case Arkanoid::Game::BrickType::STRONG:
		dto.hp = rand() % 10 + 1;
		return this->createDurable(dto);
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

std::unique_ptr<Arkanoid::Game::Brick> Arkanoid::Game::BrickFactory::create(BrickData dto)
{
	switch (static_cast<BrickType>(dto.type))
	{
	case Arkanoid::Game::BrickType::NORMAL:
		return createNormal(dto);
	case Arkanoid::Game::BrickType::STRONG:
		return this->createDurable(dto);
	default:
		return std::make_unique<Brick>(sf::Vector2f{ static_cast<float>(dto.x), static_cast<float>(dto.y) }, this->_size);
	}
}

std::unique_ptr<Arkanoid::Game::Brick> Arkanoid::Game::BrickFactory::createNormal(BrickData dto)
{
	return std::make_unique<Arkanoid::Game::Brick>(sf::Vector2f{ static_cast<float>(dto.x), static_cast<float>(dto.y) }, this->_size);
}

std::unique_ptr<Arkanoid::Game::Brick> Arkanoid::Game::BrickFactory::createDurable(BrickData dto)
{
	return std::make_unique<DurableBrick>(
		std::vector<sf::Color>(this->_colors.begin(), this->_colors.begin() + dto.hp),
		sf::Vector2f{ static_cast<float>(dto.x), static_cast<float>(dto.y) },
		this->_size
	);
}
