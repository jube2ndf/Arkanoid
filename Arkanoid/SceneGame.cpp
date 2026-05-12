#include "SceneGame.h"
#include "SceneCommand.h"
#include "CollisionSystem.h"
#include <iostream>

#define COUNT_BRICK 10

Arkanoid::Scene::Game::SceneGame::SceneGame()
{
    this->background.setSize(sf::Vector2f(
        Arkanoid::App::Settings::WINDOW_WIDTH, Arkanoid::App::Settings::WINDOW_HEIGTH)
    );
    this->background.setPosition(0, 0);
    this->background.setFillColor(sf::Color::Black);
    this->background.setOutlineThickness(10);
    this->background.setOutlineColor(sf::Color::Black);

    this->_paddle = std::make_unique<Arkanoid::Game::Paddle>(
            200,
            20,
            sf::Vector2f(static_cast<int>(Arkanoid::App::Settings::WINDOW_WIDTH / 2), Arkanoid::App::Settings::WINDOW_HEIGTH - 10)
    );

    this->_ball = std::make_unique<Arkanoid::Game::Ball>(
            Arkanoid::App::Settings::GAME_BALL_RADIUS,
            sf::Vector2f(static_cast<int>(Arkanoid::App::Settings::WINDOW_WIDTH / 2), static_cast<int>((Arkanoid::App::Settings::WINDOW_HEIGTH / 2)))
    );

    collidableBrick.clear();

    for (int i = 1; i <= COUNT_BRICK; i++)
    {
        sf::Vector2f xy = {
            static_cast<float>((App::Settings::WINDOW_WIDTH / (COUNT_BRICK + 1)) * i),
            static_cast<float>(200)
        };
        
        collidableBrick.push_back(
              std::make_unique<Arkanoid::Game::Brick>(
                xy
            )
        );
    }
    this->_managerBrick.addObservers(&this->_scoreObserver);
}

Arkanoid::Scene::SceneCommand Arkanoid::Scene::Game::SceneGame::handleInput(sf::Event& event)
{
    return Scene::SceneCommand();
}

Arkanoid::Scene::SceneCommand Arkanoid::Scene::Game::SceneGame::update(float dt)
{
    this->_paddle->update(dt);
    this->_ball->update(dt);
    handleWallCollision();
    handlePaddleCollision();
    this->_managerBrick.handleBallBrickCollision(*this->_ball.get());
    if (this->collidableBrick.empty()) {
        return Scene::SceneCommand(EnumScene::SceneRequest::Push, EnumScene::SceneType::WinGame);
    }
    return Scene::SceneCommand();
}

void Arkanoid::Scene::Game::SceneGame::draw(sf::RenderWindow& window)
{
    window.draw(this->background);
    this->_paddle->draw(window);
    this->_ball->draw(window);
    this->_managerBrick.draw(window);
}

void Arkanoid::Scene::Game::SceneGame::handleWallCollision()
{
    auto bounds = _ball->getBounds();

    if (bounds.left <= 0.f)
    {
        _ball->bounceX();
    }

    if (bounds.left + bounds.width >= App::Settings::WINDOW_WIDTH)
    {
        _ball->bounceX();
    }

    if (bounds.top <= 0.f)
    {
        _ball->bounceY();
    }

    if (bounds.top + bounds.height >= App::Settings::WINDOW_HEIGTH)
    {
        _ball->bounceY();//GameOver
    }

    bounds = this->_paddle->getBounds();

    if (bounds.left < 0.f)
    {
        this->_paddle->setPosition({ bounds.width / 2.f, this->_paddle->getPosition().y });
    }

    if (bounds.left + bounds.width> App::Settings::WINDOW_WIDTH)
    {
        this->_paddle->setPosition(
            {
                App::Settings::WINDOW_WIDTH - bounds.width / 2.f,
                this->_paddle->getPosition().y
            }
        );
    }
}

void Arkanoid::Scene::Game::SceneGame::handlePaddleCollision()
{
    if (!_ball->getBounds().intersects(_paddle->getBounds()))
        return;

    float paddleX = _paddle->getPosition().x;

    float paddleWidth = _paddle->getBounds().width;

    float ballX = _ball->getPosition().x;

    float hitPos =
        (ballX - paddleX)
        /
        (paddleWidth / 2.f);

    sf::Vector2f velocity = _ball->getVeloсity();

    float speed =
        std::sqrt(
            velocity.x * velocity.x +
            velocity.y * velocity.y
        );

    velocity.x = speed * hitPos;

    velocity.y = -std::abs(velocity.y);

    _ball->setVeloсity(velocity);

    _ball->setPosition({
        _ball->getPosition().x,
        _paddle->getBounds().top
        - _ball->getBounds().height
        });
}


