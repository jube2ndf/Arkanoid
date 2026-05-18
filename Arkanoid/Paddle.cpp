#include "Paddle.h"

Arkanoid::Game::Paddle::Paddle()
{}

Arkanoid::Game::Paddle::Paddle(float width, float height, sf::Vector2f position)
{
    this->_speed = Arkanoid::App::Settings::GAME_PADDLE_SPEED;
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

void Arkanoid::Game::Paddle::setState(const PaddleState& state)
{
    _state = state;

    auto size = _paddle.getSize();

    size.x = App::Settings::GAME_PADDLE_WIDTH * _state.widthMultiplier;
    float speed = App::Settings::GAME_PADDLE_SPEED * _state.speedMultiplier;

    _paddle.setSize(size);
    sf::FloatRect bounds = this->_paddle.getLocalBounds();
    this->_paddle.setOrigin(bounds.left + bounds.width / 2.0f,
        bounds.top + bounds.height / 2.0f);
    this->_speed = speed;
}

void Arkanoid::Game::Paddle::draw(sf::RenderWindow& window)
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
        || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(this->_paddle.getPosition().x  - this->_speed * std::min(dt, 0.016f) > 0)
            move.x -= this->_speed * std::min(dt, 0.016f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) 
        || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (this->_paddle.getPosition().x + this->_speed * std::min(dt, 0.016f) < App::Settings::WINDOW_WIDTH)
            move.x += this->_speed * std::min(dt, 0.016f);
    }
    this->_paddle.move(move);
}

Arkanoid::Game::ObjectType Arkanoid::Game::Paddle::getType() const
{
    return ObjectType::Paddle;
}
