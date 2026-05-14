#include "SaveSystem.h"
#include <iostream>
#include <fstream>
#include <filesystem>

Arkanoid::Game::SaveManager::SaveManager()
{
    if (std::filesystem::exists("save\\save_backup.txt"))
    {
        this->_lastSave = this->load("save\\save_backup.txt");
    }
}

Arkanoid::Game::SaveManager::~SaveManager()
{
    if (!this->_lastSave.bricks.empty()) // или любая проверка валидности
    {
        this->save("save\\save_backup.txt");
    }
}

void Arkanoid::Game::SaveManager::save(const GameState& state)
{
    _lastSave = state;
    if (!this->_lastSave.bricks.empty()) // или любая проверка валидности
    {
        this->save("save\\save_backup.txt");
    }
}

GameState Arkanoid::Game::SaveManager::load()
{
    if (std::filesystem::exists("save\\save_backup.txt"))
    {
        this->_lastSave = this->load("save\\save_backup.txt");
    }
    return _lastSave;
}

void Arkanoid::Game::SaveManager::save(const std::string& path)
{
    std::ofstream file{ path };
    file << _lastSave.score << "\n";
    file << _lastSave.bricks.size() << "\n";

    file << _lastSave.ballmove_x << " "
        << _lastSave.ballmove_y << " "
        << _lastSave.ball_x << " "
        << _lastSave.ball_y << "\n";

    file << _lastSave.px << "\n";

    for (const auto& b : _lastSave.bricks)
    {
        file << b.x << " "
            << b.y << " "
            << b.hp << " "
            << b.type << "\n";
    }
}

GameState Arkanoid::Game::SaveManager::load(std::string path)
{
    std::ifstream file(path);
    GameState state;

    size_t count;
    file >> state.score;
    file >> count;

    file >> state.ballmove_x
        >> state.ballmove_y
        >> state.ball_x
        >> state.ball_y;

    file >> state.px;

    for (size_t i = 0; i < count; i++)
    {
        BrickData b;
        file >> b.x >> b.y >> b.hp >> b.type;
        state.bricks.push_back(b);
    }

    return state;
}
