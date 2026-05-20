#include "WinGame.h"
#include "RecordSystem.h"
#include "AppSettings.h"
#include <algorithm>

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

void Arkanoid::Scene::WinGame::drawExtra(sf::RenderWindow& window)
{
	for (auto& text : this->_top)
		window.draw(text);
}

Arkanoid::Scene::WinGame::WinGame()
	:WinGame("You won! Should I play again?")
{}

Arkanoid::Scene::WinGame::WinGame(std::string q) :
	SceneQuestionYesNo(q)
{
	float middleX = static_cast<float>(App::Settings::WINDOW_WIDTH) / 2;
	float y_start_text = static_cast<float>(App::Settings::WINDOW_WIDTH) * 2 / 10;
	float y_step_text = static_cast<float>(App::Settings::WINDOW_WIDTH) / 20;
	auto top = App::RecordSystem::getTop();
	for (int i = 0; i < top.size() && i < 5; i++) {
		sf::Text text;
		text.setFillColor(sf::Color::White);
		text.setString(std::to_string(i+1) + ": " + std::to_string(top[top.size() - i - 1].record));
		text.setCharacterSize(30);
		text.setFont(this->_font);
		sf::FloatRect bounds = text.getLocalBounds();
		text.setOrigin(bounds.left + bounds.width / 2.0f,
			bounds.top + bounds.height / 2.0f);
		text.setPosition(middleX, y_start_text + y_step_text * (i + 1));
		this->_top.push_back(std::move(text));
	}
}
