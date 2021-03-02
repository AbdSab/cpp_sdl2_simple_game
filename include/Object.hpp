#pragma once
#include<SDL2/SDL.h>

/**
* Object Class
**/
class Map;
class Object {
    protected:
        int id; 
        SDL_Rect rect;
        SDL_Texture* texture;
        bool dynamic;
    public:
        Object(int _x, int _y, SDL_Texture* _texture);
        ~Object();
        void setId(int _id);
        void setDynamic(bool _value);
        void setPosition(int _x, int _y);
        void render(SDL_Renderer* _renderer);
        virtual void update();
};