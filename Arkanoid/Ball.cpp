#include "Ball.h"
#include <iostream>

Arkanoid::Game::Ball::Ball()
{
    std::cout << "Defalt";
}

Arkanoid::Game::Ball::Ball(float radius, sf::Vector2f pos)
{
    this->_moveVector = { -1,-1 };
    this->_speed = Arkanoid::App::Settings::GAME_BALL_SPEED;
    this->_ball.setRadius(radius);
    auto bouns = this->_ball.getLocalBounds();
    this->_ball.setOrigin(
        bouns.left + radius,
        bouns.top + radius
    );
    this->_ball.setPosition(pos);
    this->_ball.setFillColor(sf::Color::Red);
}

void Arkanoid::Game::Ball::bounceX()
{
    this->_moveVector = {
        -this->_moveVector.x,
        this->_moveVector.y
    };
}

void Arkanoid::Game::Ball::bounceY()
{
    this->_moveVector = {
        this->_moveVector.x,
        -this->_moveVector.y
    };
}

sf::Vector2f Arkanoid::Game::Ball::getPosition()
{
    return this->_ball.getPosition();
}

void Arkanoid::Game::Ball::setPosition(sf::Vector2f pos)
{
    this->_ball.setPosition(pos);
}

sf::Vector2f Arkanoid::Game::Ball::getVeloсity() const
{
    return this->_moveVector;
}

void Arkanoid::Game::Ball::setVeloсity(sf::Vector2f vel)
{
    this->_moveVector = vel;
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
    this->_ball.move(this->_moveVector * dt * this->_speed);
}

Arkanoid::Game::ObjectType Arkanoid::Game::Ball::getType() const
{
    return ObjectType::Ball;
}

float Arkanoid::Game::Ball::GetSpeed()
{
    return this->_speed;
}
