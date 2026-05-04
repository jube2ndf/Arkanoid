#include "WinGame.h"

Arkanoid::Scene::SceneCommand Arkanoid::Scene::WinGame::handlersQuestionYesNo(EnumScene::QuestionYesNo& cmd)
{
	switch (cmd)
	{
	case EnumScene::QuestionYesNo::Back:
		return SceneCommand(EnumScene::SceneRequest::Push, EnumScene::SceneType::Game);
	case EnumScene::QuestionYesNo::Yes:
		return SceneCommand(EnumScene::SceneRequest::Push, EnumScene::SceneType::Game);
	case EnumScene::QuestionYesNo::No:
		return SceneCommand(EnumScene::SceneRequest::Clear);
	default:
		break;
	}
	return SceneCommand(EnumScene::SceneRequest::None);
}

Arkanoid::Scene::WinGame::WinGame() :
	SceneQuestionYesNo("You won! Should I play again?")
{}
