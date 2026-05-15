#pragma once
#include "BrickDestroyedEvent.h"

namespace Arkanoid::Interface {
	class IBrickObserver {
    public:
        virtual ~IBrickObserver() = default;

        virtual void onBrickDestroyed(
            const Event::BrickDestroyedEvent& event
        ) = 0;
	};
}