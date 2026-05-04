#pragma once
#include "SceneRequest.h"
#include "SceneType.h"

namespace Arkanoid::Scene {
	class SceneCommand
	{
	public:
		SceneCommand() : action(EnumScene::SceneRequest::None), id(EnumScene::SceneType::None) {

		}
		SceneCommand(EnumScene::SceneRequest action) :
			action(action), id(EnumScene::SceneType::None) {

		}
		SceneCommand(EnumScene::SceneRequest action, EnumScene::SceneType id) :
			action(action), id(id) {

		}

		EnumScene::SceneRequest getAction() {
			return this->action;
		}
		EnumScene::SceneType getId() {
			return this->id;
		}

	private:
		EnumScene::SceneRequest action;
		EnumScene::SceneType id;
	};
}