#pragma once
#include<SDL2/SDL.h>

#include "Block.hpp"

#define L 0
#define T 1
#define O 2
#define S 3
#define Z 4
#define LL 5

class Tetromino {
    private:
        Block* blocks[4];
        int blockCoords[4][4] = {
            {0,0,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,1,0}
            };
        int x, y;
    public:
        Tetromino(int _x, int _y);
        void init(int _shape, SDL_Texture* _texture);
        void setPosition(int _x, int _y);
        void move(int _x, int _y);
        void rotateRight();
        void updateBlocks();
        void render(SDL_Renderer* _renderer);
};