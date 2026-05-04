#pragma once
#include "SceneQuestionYesNo.h"
namespace Arkanoid::Scene {
    class WinGame :
        public SceneQuestionYesNo
    {
    protected:
        // Унаследовано через SceneQuestionYesNo
        SceneCommand handlersQuestionYesNo(EnumScene::QuestionYesNo& cmd) override;
    public:
        WinGame();
    };
}