#include "SceneGame.h"
#include "SceneCommand.h"
#include "CollisionSystem.h"

Arkanoid::Scene::Game::SceneGame::SceneGame()
{
    this->background.setSize(sf::Vector2f(
        Arkanoid::App::Settings::WINDOW_WIDTH, Arkanoid::App::Settings::WINDOW_HEIGTH)
    );
    this->background.setPosition(0, 0);
    this->background.setFillColor(sf::Color(0, 200, 0));
    this->background.setOutlineThickness(10);
    this->background.setOutlineColor(sf::Color::Red);

    collidableObjects.clear();

    collidableObjects.push_back(&this->_paddle);
    collidableObjects.push_back(&this->_ball);

    //for (auto& brick : bricks)
    //{
    //    collidableObjects.push_back(brick.get());
    //}
}

Arkanoid::Scene::SceneCommand Arkanoid::Scene::Game::SceneGame::handleInput(sf::Event& event)
{
    
    return Scene::SceneCommand();
}

Arkanoid::Scene::SceneCommand Arkanoid::Scene::Game::SceneGame::update(float dt)
{
    this->_paddle.update(dt);
    this->_ball.update(dt);
    handleWallCollision();
    Arkanoid::Game::CollisionSystem::check(collidableObjects);
    return Scene::SceneCommand();
}

void Arkanoid::Scene::Game::SceneGame::draw(sf::RenderWindow& window)
{
    window.draw(this->background);
    this->_paddle.drow(window);
    this->_ball.drow(window);
}

void Arkanoid::Scene::Game::SceneGame::handleWallCollision()
{
    auto bounds = _ball.getBounds();

    if (bounds.left <= 0.f)
    {
        _ball.bounceX();
    }

    if (bounds.left + bounds.width >= App::Settings::WINDOW_WIDTH)
    {
        _ball.bounceX();
    }

    if (bounds.top <= 0.f)
    {
        _ball.bounceY();
    }

    if (bounds.top + bounds.height >= App::Settings::WINDOW_HEIGTH)
    {
        _ball.bounceY();//GameOver
    }

    auto bounds = this->_paddle.getBounds();

    if (bounds.left < 0.f)
    {
        this->_paddle.setPosition({ bounds.width / 2.f, this->_paddle.getPosition().y });
    }

    if (bounds.left + bounds.width > App::Settings::WINDOW_HEIGTH)
    {
        this->_paddle.setPosition(
            {
                App::Settings::WINDOW_WIDTH - bounds.width / 2.f,
                this->_paddle.getPosition().y
            }
        );
    }
}

void Arkanoid::Scene::Game::SceneGame::handlePaddleCollision()
{
    {
        if (!_ball.getBounds().intersects(_paddle.getBounds()))
            return;

        float paddleX = _paddle.getPosition().x;

        float paddleWidth = _paddle.getBounds().width;

        float ballX = _ball.getPosition().x;

        float hitPos =
            (ballX - paddleX)
            /
            (paddleWidth / 2.f);

        sf::Vector2f velocity = _ball.getVelocity();

        float speed =
            std::sqrt(
                velocity.x * velocity.x +
                velocity.y * velocity.y
            );

        velocity.x = speed * hitPos;

        velocity.y = -std::abs(velocity.y);

        _ball.setVelocity(velocity);

        _ball.setPosition({
            _ball.getPosition().x,
            _paddle.getBounds().top
            - _ball.getBounds().height
            });
    }


