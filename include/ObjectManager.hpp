#pragma once

#include <vector>
#include "Object.hpp"

class ObjectManager {
    public:
        static int length;
        static std::vector<Object*> objects;
        static void addObject(Object* object);
        static void update(SDL_Renderer* _renderer);
};