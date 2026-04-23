#pragma once
#include "IScene.h"
namespace Arkanoid::Scene::Game {
	class SceneGame: public Interface::IScene
	{
	public:
		SceneGame();

		// Унаследовано через IScene
		Scene::SceneCommand handleInput(sf::Event& event) override;
		Scene::SceneCommand update(float dt) override;
		void draw(sf::RenderWindow& window) override;
	private:

	};
}