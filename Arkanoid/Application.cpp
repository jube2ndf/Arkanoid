#include "Application.h"
#include "AppSettings.h"
#include "SceneFactory.h"
#include "SceneManager.h"

Arkanoid::App::Application::Application(const std::string& appName)
	: window(sf::VideoMode(App::Settings::WINDOW_WIDTH, App::Settings::WINDOW_HEIGTH), appName)
{}

Arkanoid::App::Application::~Application()
{}

void Arkanoid::App::Application::Run()
{
    unsigned int seed = (unsigned int)time(nullptr);
    srand(seed);

    sf::Clock game_clock;
    sf::Time lastTime = game_clock.getElapsedTime();

    Arkanoid::Scene::SceneFactory factory;
    //init factory
    {
        
    }
    Scene::SceneManager sceneManager(factory);

    while (window.isOpen())
    {
        float dt = game_clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            sceneManager.HandelInput(event, dt);
        }
        sceneManager.Update(dt);
        window.clear();
        sceneManager.Draw(window);
        window.display();
    }
    return;
}
