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
		return true;
	}
	this->_brick.setFillColor(this->_damageColor[this->hitPoint - 1]);
	return false;
}
