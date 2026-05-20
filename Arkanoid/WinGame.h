#pragma once
#include "SceneQuestionYesNo.h"
namespace Arkanoid::Scene {
    class WinGame :
        public SceneQuestionYesNo
    {
    protected:
        std::vector<sf::Text> _top;
        // Унаследовано через SceneQuestionYesNo
        SceneCommand handlersQuestionYesNo(EnumScene::QuestionYesNo& cmd) override;
        void drawExtra(sf::RenderWindow& window) override;
    public:
        WinGame();
        WinGame(std::string q);
    };
}