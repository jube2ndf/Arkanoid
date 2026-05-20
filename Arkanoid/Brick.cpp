#include "Brick.h"
#include "AppSettings.h"

Arkanoid::Game::Brick::Brick(sf::Vector2f position)
{
    this->_brick.setSize({ App::Settings::BRICK_WIDTH, App::Settings::BRICK_HEIGTH });
    this->_brick.setFillColor(sf::Color::Blue);
    sf::FloatRect bounds = this->_brick.getLocalBounds();
    this->_brick.setOrigin(bounds.left + bounds.width / 2.0f,
        bounds.top + bounds.height / 2.0f);
    this->_brick.setPosition(position);
}

Arkanoid::Game::Brick::Brick(sf::Vector2f position, sf::Vector2f size) :
    Brick(position)
{
    this->_brick.setSize(size);
}

bool Arkanoid::Game::Brick::onHit()
{
    this->notify(1);
    return true;
}

int Arkanoid::Game::Brick::getHP()
{
    return 1;
}

BrickData Arkanoid::Game::Brick::getData()
{
    BrickData dto;
    auto pos = this->_brick.getPosition();
    dto.x = static_cast<int>(pos.x);
    dto.y = static_cast<int>(pos.y);
    dto.hp = this->getHP();
    dto.type = static_cast<int>(this->getBrickType());
    return dto;
}

void Arkanoid::Game::Brick::draw(sf::RenderWindow& window)
{
    window.draw(this->_brick);
}

Arkanoid::Game::ObjectType Arkanoid::Game::Brick::getType() const
{
    return ObjectType::Brick;
}

Arkanoid::Game::BrickType Arkanoid::Game::Brick::getBrickType() const
{
    return BrickType::NORMAL;
}

sf::FloatRect Arkanoid::Game::Brick::getBounds() const
{
    return this->_brick.getGlobalBounds();
}

sf::Vector2f Arkanoid::Game::Brick::getPosition()
{
    return this->_brick.getPosition();
}

void Arkanoid::Game::Brick::setPosition(sf::Vector2f position)
{
    this->_brick.setPosition(position);
}
