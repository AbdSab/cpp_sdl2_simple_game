#pragma once
#include<SDL2/SDL.h>

class Block {
    private: 
        SDL_Rect rect;
        SDL_Texture* texture;
    public:
        Block(int _x, int _y, SDL_Texture* _texture);
        void setPosition(int _x, int _y);
        void render(SDL_Renderer* _renderer);
        int getX() {return rect.x;};
};