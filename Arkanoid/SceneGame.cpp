#include "SceneGame.h"
#include "SceneCommand.h"
#include "CollisionSystem.h"
#include <iostream>
#include "StandartBonus.h"

constexpr auto COUNT_BRICK = 10;

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

    this->_managerBrick.addObservers(&this->_scoreObserver);
    auto state = this->_saveManager.load();
    if (state.bricks.size() != 0) {
        this->restoreFromMemento(state);
    }
    this->_context.ball = this->_ball.get();
    this->_context.paddle = this->_paddle.get();
    this->_context.score = &this->_scoreObserver;
    this->_context.effects = &this->_effects;
    _managerBrick.addObserver(this);
}

Arkanoid::Scene::SceneCommand Arkanoid::Scene::Game::SceneGame::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::F5)
        {
            auto state = createMemento();
            _saveManager.save(state);
        }

        if (event.key.code == sf::Keyboard::F9)
        {
            auto state = _saveManager.load();
            restoreFromMemento(state);
        }
    }
    return Scene::SceneCommand();
}

Arkanoid::Scene::SceneCommand Arkanoid::Scene::Game::SceneGame::update(float dt)
{
    // Updating moving objects
    this->_paddle->update(dt);
    this->_ball->update(dt);

    // Collision checking
    handleWallCollision();
    handlePaddleCollision();
    this->_managerBrick.handleBallBrickCollision(*this->_ball.get());

    // Updating bonus
    for (auto& bonus : _bonuses)
        bonus->update(dt);
    for (auto& effect : _effects)
        effect->update(_context, dt);
    
    // Delete old bonus, effects
    clearBonus();
    clearEffects();

    for (auto& bonus : _bonuses)
    {
        if (bonus->getBounds().intersects(_paddle->getBounds()))
        {
            bonus->apply(_context);
            bonus->kill();
        }
    }

    // Win game?
    if (this->_managerBrick.getCount() == 0) {
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
    for (auto& bonus : this->_bonuses)
        bonus->draw(window);
}

GameState Arkanoid::Scene::Game::SceneGame::createMemento()
{
    GameState state = this->_managerBrick.getState();

    state.score = this->_scoreObserver.getScore();

    // paddle
    state.px = _paddle->getPosition().x;

    // ball
    state.ball_x = _ball->getPosition().x;
    state.ball_y = _ball->getPosition().y;
    state.ballmove_x = _ball->getVeloсity().x;
    state.ballmove_y = _ball->getVeloсity().y;

    return state;
}

void Arkanoid::Scene::Game::SceneGame::restoreFromMemento(const GameState& state)
{
    this->_managerBrick.setState(state);
    this->_ball->setVeloсity(sf::Vector2f(state.ballmove_x, state.ballmove_y));
    this->_ball->setPosition(sf::Vector2f(state.ball_x, state.ball_y));
    this->_paddle->setPosition(
        sf::Vector2f(
            state.px,
            this->_paddle->getPosition().y
        )
    );
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

void Arkanoid::Scene::Game::SceneGame::handleBonusCollision()
{
    for (auto& bonus : this->_bonuses)
    {
        if (bonus->getBounds().top + bonus->getBounds().height >= App::Settings::WINDOW_HEIGTH)
        {
            bonus->kill();
        }
        if (bonus->getBounds().intersects(_paddle->getBounds()))
        {
            bonus->apply(this->_context);
            bonus->kill();
        }
    }
}

void Arkanoid::Scene::Game::SceneGame::clearBonus()
{
    _bonuses.erase(
        std::remove_if(_bonuses.begin(), _bonuses.end(),
            [](auto& b) { return !b->isAlive(); }),
        _bonuses.end()
    );
}

void Arkanoid::Scene::Game::SceneGame::clearEffects()
{
    _effects.erase(
        std::remove_if(_effects.begin(), _effects.end(),
            [](auto& e) { return !e->isActive(); }),
        _effects.end()
    );
}

void Arkanoid::Scene::Game::SceneGame::onBrickDestroyed(const Event::BrickDestroyedEvent& event)
{
    if (rand() % 100 < 30)
    {
        _bonuses.push_back(
            std::make_unique<
            Arkanoid::Game::StandartBonus
            >(event.position)
        );
    }
}