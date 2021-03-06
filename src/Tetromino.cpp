#include "Tetromino.hpp"
#include<iostream>

Tetromino::Tetromino(int _x, int _y) : x(_x), y(_y) {}

void Tetromino::setPosition(int _x, int _y) {
    x = _x; y = _y;
}

void Tetromino::move(int _x, int _y) {
    x += _x;
    y += _y;
}

void Tetromino::rotateRight() {
    const int N = 4;
    for (int x = 0; x < N / 2; x++) {
        for (int y = x; y < N - x - 1; y++) {
            int temp = blockCoords[x][y];
            blockCoords[x][y] = blockCoords[y][N - 1 - x];
            blockCoords[y][N - 1 - x] 
                = blockCoords[N - 1 - x][N - 1 - y]; 
            blockCoords[N - 1 - x][N - 1 - y] 
                = blockCoords[N - 1 - y][x];
            blockCoords[N - 1 - y][x] = temp; 
        } 
    } 
}

void Tetromino::init(int _shape, SDL_Texture* _texture) {
    for(int i=0; i<4; i++){
        Block* block = new Block(0, 0, _texture);
        blocks[i] = block;
    }
    updateBlocks();
}

void Tetromino::updateBlocks() {
    int counter = 0;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++){
            if(blockCoords[i][j] == 1) {
                blocks[counter]->setPosition(x + i * 16, y + j * 16);
                counter++;
                if(counter > 4) break;
            }
        }
    };
}

void Tetromino::render(SDL_Renderer* _renderer){
    for(int i=0; i<4; i++){
        std::cout << blocks[i]->getX() << std::endl;
        blocks[i]->render(_renderer);
    }
}