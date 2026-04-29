#include "Paddle.h"

Arkanoid::Game::Paddle::Paddle(float width, float height, sf::Vector2f position)
{
    this->_paddle.setSize({ width, height });
    sf::FloatRect bounds = this->_paddle.getLocalBounds();
    this->_paddle.setOrigin(bounds.left + bounds.width / 2.0f,
        bounds.top + bounds.height / 2.0f);
    this->_paddle.setPosition(position);
    this->_paddle.setFillColor(sf::Color::White);
}

sf::Vector2f Arkanoid::Game::Paddle::getPosition()
{
    return this->_paddle.getPosition();
}

void Arkanoid::Game::Paddle::setPosition(sf::Vector2f newP)
{
    this->_paddle.setPosition(newP);
}

void Arkanoid::Game::Paddle::drow(sf::RenderWindow& window)
{
    window.draw(this->_paddle);
}

sf::FloatRect Arkanoid::Game::Paddle::getBounds() const
{
    return this->_paddle.getGlobalBounds();
}

void Arkanoid::Game::Paddle::update(float dt)
{
    sf::Vector2f move{0,0};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        move.x -= this->_speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        move.x += this->_speed * dt;

    this->_paddle.move(move);
}

Arkanoid::Game::ObjectType Arkanoid::Game::Paddle::getType() const
{
    return ObjectType::Paddle;
}
