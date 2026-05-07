#include "BricksManager.h"
#include <memory>
#include "BrickFactory.h"

#define SIZE_BRICK_ZONE 0.3

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
    int cols = this->levels[level][0].size();
    int rows = this->levels[level].size();

    float brickWidth = regionBrickWidth / cols;
    float brickHeight = regionBrickHeight / rows;
    float offsetX = (App::Settings::WINDOW_WIDTH - cols * brickWidth) / 2;

    BrickFactory factory = BrickFactory(sf::Vector2f(brickWidth, brickHeight));

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (this->levels[level][y][x] == 1)
            {
                this->collidableBrick.push_back(
                    factory.create(
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

void Arkanoid::Game::BricksManager::handleBallBrickCollision(Game::Ball& ball)
{
    for (auto brick = this->collidableBrick.begin();
        brick != this->collidableBrick.end();
        brick++
        ) {
        sf::FloatRect bounds = brick->get()->getBounds();

        if (!ball.getBounds().intersects(brick->get()->getBounds()))
            continue;

        auto ballBounds = ball.getBounds();
        auto brickBounds = (*brick)->getBounds();

        bool hitFromLeft = ball.getPosition().x + ballBounds.width <= brickBounds.left;
        bool hitFromRight = ball.getPosition().x >= brickBounds.left + brickBounds.width;

        if (hitFromLeft || hitFromRight)
        {
            ball.bounceX();
        }
        else
        {
            ball.bounceY();
        }
        if(brick->get()->onHit())
            brick = this->collidableBrick.erase(brick);
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
