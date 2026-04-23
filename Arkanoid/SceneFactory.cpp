#include "SceneFactory.h"

Arkanoid::Scene::SceneFactory::SceneFactory()
{
    this->_factory = {};
}

std::unique_ptr<Arkanoid::Interface::IScene> Arkanoid::Scene::SceneFactory::Create(EnumScene::SceneType stateID)
{
    auto it = _factory.find(stateID);
    if (it != _factory.end())
        return it->second();
    return nullptr;
}
