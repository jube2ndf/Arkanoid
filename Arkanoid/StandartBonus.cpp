#include "StandartBonus.h"

Arkanoid::Game::StandartBonus::StandartBonus(sf::Vector2f pos, std::unique_ptr<Interface::IEffect> effect)
    :_effect(std::move(effect))
{
    _shape.setSize({ 20.f, 20.f });
    _shape.setFillColor(sf::Color::Green);
    _shape.setPosition(pos);
}

void Arkanoid::Game::StandartBonus::update(float dt)
{
    _shape.move(0.f, _speed * dt);

    if (_shape.getPosition().y > App::Settings::WINDOW_HEIGTH)
        _alive = false;
}

void Arkanoid::Game::StandartBonus::draw(sf::RenderWindow & window)
{
    window.draw(_shape);
}

void Arkanoid::Game::StandartBonus::apply(Game::GameContext & ctx)
{
    if (this->_effect)
    {
        this->_effect.get()->onApply(ctx);

        ctx.effects->push_back(std::move(_effect));
    }
    this->kill();
}

void Arkanoid::Game::StandartBonus::kill()
{
    this->_alive = false;
}

sf::FloatRect Arkanoid::Game::StandartBonus::getBounds() const
{
    return _shape.getGlobalBounds();
}

bool Arkanoid::Game::StandartBonus::isAlive() const
{
    return this->_alive;
}
