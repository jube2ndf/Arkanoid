#include "Application.h"
#include "AppSettings.h"
#include "SceneFactory.h"
#include "SceneManager.h"
#include "SceneGame.h"
#include "WinGame.h"
#include <iostream>

Arkanoid::App::Application::Application(const std::string& appName)
	: window(sf::VideoMode(App::Settings::WINDOW_WIDTH, App::Settings::WINDOW_HEIGTH), appName)
{}

Arkanoid::App::Application::~Application()
{}

void Arkanoid::App::Application::Run()
{
    unsigned int seed = (unsigned int)time(nullptr);
    srand(seed);

    

    Arkanoid::Scene::SceneFactory factory;
    //init factory
    {
        factory.RegisterScene<Scene::Game::SceneGame>(EnumScene::SceneType::Game);
        factory.RegisterScene<Scene::WinGame>(EnumScene::SceneType::WinGame);
    }
    Scene::SceneManager sceneManager(factory);

    while (window.isOpen())
    {
        float dt = sceneManager.restart();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            sceneManager.HandelInput(event);
        }
        sceneManager.Update(dt);
        window.clear();
        sceneManager.Draw(window);
        window.display();
    }
    return;
}
