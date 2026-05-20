#include "ScoreSystem.h"
#include "iostream"

void Arkanoid::Game::ScoreSystem::setState(GameState state)
{
	this->score = state.score;
}

void Arkanoid::Game::ScoreSystem::onNotify(int points)
{
	this->score += points;
	std::cout << this->score << "\n";
}

int Arkanoid::Game::ScoreSystem::getScore()
{
	return this->score;
}

void Arkanoid::Game::ScoreSystem::reset()
{
	this->score = 0;
}
