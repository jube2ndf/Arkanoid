#include "CollisionSystem.h"

void Arkanoid::Game::CollisionSystem::check(std::vector<GameObject*>& objects)
{
    for (size_t i = 0; i < objects.size(); ++i)
    {
        for (size_t j = i + 1; j < objects.size(); ++j)
        {
            auto& a = objects[i];
            auto& b = objects[j];

            if (a->getBounds().intersects(b->getBounds()))
            {
                a->onCollision(*b);
                b->onCollision(*a);
            }
        }
    }
}
