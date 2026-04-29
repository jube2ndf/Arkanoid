#pragma once
#include <SFML/Graphics.hpp>
#include <string>
namespace Arkanoid::App {
	class Application
	{
	public:
		Application(const std::string& appName);
		~Application();
		void Run();
	private:
		sf::RenderWindow window;
	};
}