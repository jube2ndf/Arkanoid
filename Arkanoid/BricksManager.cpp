#include "BricksManager.h"
#include <memory>
#include "BrickFactory.h"
#include <iostream>
#include "BrickDestroyedEvent.h"

constexpr auto SIZE_BRICK_ZONE = 0.3;

Arkanoid::Game::BricksManager::BricksManager()
    :BricksManager(App::Settings::WINDOW_WIDTH, App::Settings::WINDOW_HEIGTH * SIZE_BRICK_ZONE, rand() % (this->levels.size() - 0 + 1))
{

}

Arkanoid::Game::BricksManager::BricksManager(float regionBrickWidth, float regionBrickHeight)
    :BricksManager(regionBrickWidth, regionBrickHeight, rand() % (this->levels.size() - 0 + 1))
{

}

Arkanoid::Game::BricksManager::BricksManager(float regionBrickWidth, float regionBrickHeight, int level)
{
    this->cols = this->levels[level][0].size();
    this->rows = this->levels[level].size();
    this->lvl = level;

    brickWidth = regionBrickWidth / this->cols;
    brickHeight = regionBrickHeight / this->rows;
    float offsetX = (App::Settings::WINDOW_WIDTH - this->cols * brickWidth) / 2;

    this->_factory = std::make_unique<BrickFactory>(sf::Vector2f(brickWidth, brickHeight));

    for (int y = 0; y < this->rows; y++)
    {
        for (int x = 0; x < this->cols; x++)
        {
            if (this->levels[level][y][x] == 1)
            {
                this->collidableBrick.push_back(
                    this->_factory->create(
                        BrickType::RANDOM, 
                        sf::Vector2f(
                            offsetX + x * brickWidth,
                            y* brickHeight
                        )
                    )
                );
            }
        }
    }
}

void Arkanoid::Game::BricksManager::addObservers(Interface::IObserver* obs)
{
    for (auto& brick : this->collidableBrick) {
        brick->addObservers(obs);
    }
}

void Arkanoid::Game::BricksManager::handleBallBrickCollision(Game::Ball& ball)
{
    for (auto brick = this->collidableBrick.begin();
        brick != this->collidableBrick.end();
        brick++
        ) {
        sf::FloatRect bounds = brick->get()->getBounds();

        if (!ball.getBounds().intersects(brick->get()->getBounds()))
            continue;
        ball.handleCollision(*brick->get());
        if (brick->get()->onHit())
        {
            Event::BrickDestroyedEvent event;
            event.position = brick->get()->getPosition();

            for (auto* obs : _observers)
            {
                obs->onBrickDestroyed(event);
            }
            brick = this->collidableBrick.erase(brick);
        }
        return;
    }
}

void Arkanoid::Game::BricksManager::draw(sf::RenderWindow& window)
{
    for (auto brick = this->collidableBrick.begin();
        brick != this->collidableBrick.end();
        brick++
        )
    {
        brick->get()->draw(window);
    }
}

int Arkanoid::Game::BricksManager::getCount()
{
    return static_cast<int>(this->collidableBrick.size());
}

GameState Arkanoid::Game::BricksManager::getState()
{
    GameState state;

    for (const auto& brick : this->collidableBrick)
    {
        state.bricks.push_back(brick->getData());
        std::cout << brick->getPosition().x << "," << brick->getPosition().y << "\n";
        std::cout << state.bricks.back().x << "," << state.bricks.back().y << "\n\n";
    }
    return state;
}

void Arkanoid::Game::BricksManager::setState(GameState dto)
{
    this->collidableBrick.clear();
    for (const auto& brick : dto.bricks)
    {
        this->collidableBrick.push_back(
            this->_factory->create(brick)
        );
    }
}

void Arkanoid::Game::BricksManager::addObserver(Interface::IBrickObserver* obs)
{
    _observers.push_back(obs);
}
