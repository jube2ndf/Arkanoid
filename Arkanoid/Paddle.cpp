#include "Paddle.h"

Arkanoid::Game::Paddle::Paddle(float width, float height, sf::Vector2f position)
{
    this->_paddle.setSize({ width, height });
    this->_paddle.setPosition(position);
    this->_paddle.setFillColor(sf::Color::White);
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
    float move = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        move -= this->_speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        move += this->_speed * dt;

    this->_paddle.move(move, this->_paddle.getPosition().y);
}
