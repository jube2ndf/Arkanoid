#include "ScoreSystem.h"

void Arkanoid::Game::ScoreSystem::setState(GameState state)
{
	this->score = state.score;
}

void Arkanoid::Game::ScoreSystem::onNotify(int points)
{
	this->score += points;
}

int Arkanoid::Game::ScoreSystem::getScore()
{
	return this->score;
}

void Arkanoid::Game::ScoreSystem::reset()
{
	this->score = 0;
}
