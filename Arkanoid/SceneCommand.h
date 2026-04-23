#pragma once
#include "SceneRequest.h"
#include "SceneType.h"

namespace Arkanoid::Scene {
	struct SceneCommand
	{
		EnumScene::SceneRequest action;
		EnumScene::SceneType id;

		SceneCommand() : action(EnumScene::SceneRequest::None), id(EnumScene::SceneType::None) {

		}
		SceneCommand(EnumScene::SceneRequest action) :
			action(action), id(EnumScene::SceneType::None) {

		}
		SceneCommand(EnumScene::SceneRequest action, EnumScene::SceneType id) :
			action(action), id(id) {

		}
	};
}