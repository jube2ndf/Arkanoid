#pragma once
namespace Arkanoid::Interface {
	class IObserver {
	public:
		virtual void onNotify(int points) = 0;
		virtual ~IObserver() = default;
	};
}