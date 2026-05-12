#pragma once
#include <vector>
#include "IObserver.h"


namespace Arkanoid::Game {
	class Subject
	{
	public:
		void addObservers(Interface::IObserver* obs) {
			this->observers.push_back(obs);
		}

		void notify(int points) {
			for (auto* obs : this->observers)
				obs->onNotify(points);
		}

	protected:
		std::vector<Interface::IObserver*> observers;
	};
}