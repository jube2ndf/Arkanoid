#include "SceneGame.h"
#include "SceneCommand.h"

Arkanoid::Scene::Game::SceneGame::SceneGame()
{

}

Arkanoid::Scene::SceneCommand Arkanoid::Scene::Game::SceneGame::handleInput(sf::Event& event)
{
    return Scene::SceneCommand();
}

Arkanoid::Scene::SceneCommand Arkanoid::Scene::Game::SceneGame::update(float dt)
{
    return Scene::SceneCommand();
}

void Arkanoid::Scene::Game::SceneGame::draw(sf::RenderWindow& window)
{}
