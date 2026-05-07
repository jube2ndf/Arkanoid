#include <SFML/Graphics.hpp>
#include "Application.h"

using namespace sf;

int main()
{
	std::srand(std::time(0));
	Arkanoid::App::Application app("Arkanoid");
	app.Run();
	return 0;
}
