#pragma once
#include "GameState.h"
#include <string>

namespace Arkanoid::Game {
	class SaveManager
	{
	public:
		SaveManager();
		~SaveManager();

		void save(const GameState& state);
		GameState load();
	protected:
		GameState _lastSave;
		void save(const std::string& path);
		GameState load(std::string path);
	};
}