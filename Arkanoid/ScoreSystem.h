#pragma once
#include "IObserver.h"

namespace Arkanoid::Game {
    class ScoreSystem :
        public Interface::IObserver
    {
    public:
        // Унаследовано через IObserver
        void onNotify(int points) override;
        int getScore();
        void reset();
    private:
        int score = 0;
    };
}