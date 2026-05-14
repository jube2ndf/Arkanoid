#pragma once
#include "IObserver.h"
#include "GameState.h"

namespace Arkanoid::Game {
    class ScoreSystem :
        public Interface::IObserver
    {
    public:
        
        // Унаследовано через IObserver
        void onNotify(int points) override;
        int getScore();
        void reset();
        void setState(GameState state);
    private:
        int score = 0;
    };
}