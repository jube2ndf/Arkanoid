#pragma once
#include "IBonus.h"
#include "IEffect.h"
namespace Arkanoid::Game {
    class StandartBonus :
        public Interface::IBonus
    {
    public:
        StandartBonus(sf::Vector2f pos, std::unique_ptr<Interface::IEffect> effect);
        // Унаследовано через IBonus
        void update(float dt) override;
        void draw(sf::RenderWindow& window) override;
        void apply(Game::GameContext& ctx) override;
        void kill() override;
        sf::FloatRect getBounds() const override;
        bool isAlive() const override;

    protected:
        std::unique_ptr<Interface::IEffect> _effect;
        sf::RectangleShape _shape;
        float _speed = 150.f;
        bool _alive = true;
    };
}