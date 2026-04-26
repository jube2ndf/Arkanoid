#include "Ball.h"

Arkanoid::Game::Ball::Ball(float radius, sf::Vector2f pos)
{
    this->_ball.setRadius(radius);
    this->_ball.setPosition(pos);
    this->_ball.setFillColor(sf::Color::Red);
}

void Arkanoid::Game::Ball::drow(sf::RenderWindow& window)
{
    window.draw(this->_ball);
}

sf::FloatRect Arkanoid::Game::Ball::getBounds() const
{
    return this->_ball.getGlobalBounds();
}

void Arkanoid::Game::Ball::update(float dt)
{
    this->_ball.move(this->_speed * dt);
}

Arkanoid::Game::ObjectType Arkanoid::Game::Ball::getType() const
{
    return ObjectType::Ball;
}

void Arkanoid::Game::Ball::onCollision(GameObject& other)
{

}
