#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

namespace Arkanoid::Game {
	class CollisionSystem
	{
	public:
		static void check(std::vector<GameObject*>& objects);
	};
}