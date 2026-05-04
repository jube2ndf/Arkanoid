#include "SceneManager.h"

Arkanoid::Scene::SceneManager::SceneManager(Scene::SceneFactory& factory)
	:_factory(factory)
{
	this->requestPush(EnumScene::SceneType::Game);
}

void Arkanoid::Scene::SceneManager::HandelInput(sf::Event & event)
{
	if (_scenes.empty())
		return;

	SceneCommand cmd = _scenes.back()->handleInput(event);
	if (cmd.getAction() != EnumScene::SceneRequest::None)
		_commands.push_back(std::move(cmd));
}

void Arkanoid::Scene::SceneManager::Update(float dt)
{
	if (_scenes.empty())
		return;

	SceneCommand cmd = _scenes.back()->update(dt);
	if (cmd.getAction() != EnumScene::SceneRequest::None)
		_commands.push_back(std::move(cmd));
	this->processCommand();
}

void Arkanoid::Scene::SceneManager::Draw(sf::RenderWindow & window)
{
	if (!this->_scenes.empty())
		this->_scenes.back()->draw(window);
	else
		window.close();
}

float Arkanoid::Scene::SceneManager::restart()
{
	return game_clock.restart().asSeconds();
}

void Arkanoid::Scene::SceneManager::requestPop()
{
	if (_scenes.size() != 0)
		this->_scenes.pop_back();
}

void Arkanoid::Scene::SceneManager::requestPush(EnumScene::SceneType id)
{
	_scenes.push_back(_factory.Create(id));
}

void Arkanoid::Scene::SceneManager::requestClear() 
{
	this->_scenes.clear();
}

void Arkanoid::Scene::SceneManager::processCommand()
{
	for (auto& cmd : this->_commands) {
		switch (cmd.getAction())
		{
		case EnumScene::SceneRequest::Clear:
			this->requestClear();
			break;
		case EnumScene::SceneRequest::Pop:
			this->requestPop();
			break;
		case EnumScene::SceneRequest::Push:
			this->requestPush(cmd.getId());
			break;
		case EnumScene::SceneRequest::Switch:
			this->requestPop();
			this->requestPush(cmd.getId());
			break;
		default:
			break;
		}
	}
	this->_commands.clear();
}
