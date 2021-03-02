#include "Object.hpp"

Object::Object(int _x, int _y, SDL_Texture* _texture) {
    rect.x = _x; rect.y = _y; rect.w=32, rect.h=32;
    texture = _texture;
    dynamic = false;
}

void Object::setId(int _id) {
    id = _id;
}

void Object::setDynamic(bool value) {
    dynamic = value;
}

void Object::setPosition(int _x, int _y) {
    rect.x = _x, rect.y = _y;
}

void Object::render(SDL_Renderer* _renderer){
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
}

void Object::update() {}