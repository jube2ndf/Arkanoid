#pragma once
#include <map>
#include <functional>
#include "IScene.h"
#include "SceneType.h"

namespace Arkanoid::Scene {
	class SceneFactory
	{
	public:
		SceneFactory();

        template<typename T>
        void RegisterScene(EnumScene::SceneType id)
        {

			this->_factory[id] = []()
                {
                    return std::make_unique<T>();
                };
        }

		std::unique_ptr<Arkanoid::Interface::IScene> Create(EnumScene::SceneType stateID);

		SceneFactory& operator=(const SceneFactory&) = delete;
	private:
		std::map<EnumScene::SceneType, std::function<std::unique_ptr<Arkanoid::Interface::IScene>()>> _factory;
	};
}