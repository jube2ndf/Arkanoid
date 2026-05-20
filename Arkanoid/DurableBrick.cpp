#include "DurableBrick.h"

Arkanoid::Game::DurableBrick::DurableBrick(const std::vector<sf::Color>& damageColor, sf::Vector2f position)
	:Brick(position)
{
	for (auto iter : damageColor) {
		this->_damageColor.push_back(iter);
	}
	this->_brick.setFillColor(this->_damageColor.back());
	this->hitPoint = this->_damageColor.size();
}

Arkanoid::Game::DurableBrick::DurableBrick(const std::vector<sf::Color>& damageColor, sf::Vector2f position, sf::Vector2f size)
	:Brick(position, size)
{
	for (auto iter : damageColor) {
		this->_damageColor.push_back(iter);
	}
	this->_brick.setFillColor(this->_damageColor.back());
	this->hitPoint = this->_damageColor.size();
}



bool Arkanoid::Game::DurableBrick::onHit()
{
	this->hitPoint--;
	if (this->hitPoint == 0) {
		this->notify(this->_damageColor.size());
		return true;
	}
	this->_brick.setFillColor(this->_damageColor[this->hitPoint - 1]);
	return false;
}

int Arkanoid::Game::DurableBrick::getHP()
{
	return this->hitPoint;
}


Arkanoid::Game::BrickType Arkanoid::Game::DurableBrick::getBrickType() const
{
	return BrickType::STRONG;
}

BrickData Arkanoid::Game::DurableBrick::getData()
{
	BrickData dto;
	sf::Vector2f pos = this->_brick.getPosition();
	dto.x = static_cast<int>(pos.x);
	dto.y = static_cast<int>(pos.y);
	dto.hp = this->hitPoint;
	dto.type = static_cast<int>(this->getType());
	return dto;
}
