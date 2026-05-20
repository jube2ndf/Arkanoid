#pragma once
#include "IScene.h"
#include "QuestionYesNo.h"
#include "MenuFunctionality.h"

namespace Arkanoid::Scene {
    class SceneQuestionYesNo :
        public Interface::IScene
    {
    public:
        SceneQuestionYesNo(std::string question);

        virtual SceneCommand handlersQuestionYesNo(EnumScene::QuestionYesNo& cmd) = 0;
        // Унаследовано через IScene
        Scene::SceneCommand handleInput(sf::Event& event) override;
        Scene::SceneCommand update(float dt) override;
        void draw(sf::RenderWindow& window) override;
        virtual void drawExtra(sf::RenderWindow& window) {}
    protected:

        sf::Font _font;
        sf::Text _question;

        const std::vector<std::string> _textMenuOptions = {
            "Yes",
            "No"
        };

        std::vector<sf::Text> _menuOptions;

        MenuFunctionality<EnumScene::QuestionYesNo> _inputMenu{};
    };
}