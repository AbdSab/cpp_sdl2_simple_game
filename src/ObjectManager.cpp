#include "ObjectManager.hpp"
#include "Object.hpp"
#include <vector>

int ObjectManager::length = 0;

std::vector<Object*> ObjectManager::objects; 

void ObjectManager::addObject(Object* object) {
    object->setId(++length);
    objects.push_back(object);
}

void ObjectManager::update(SDL_Renderer* _renderer) {
    for(Object* object : objects) {
        object->update();
        object->render(_renderer);
    }
}