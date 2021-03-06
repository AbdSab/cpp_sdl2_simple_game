#include "Block.hpp"

Block::Block(int _x, int _y, SDL_Texture* _texture) {
    rect.x = _x; rect.y=_y; rect.w=16; rect.h=16;
    texture = _texture;
};
void Block::setPosition(int _x, int _y) {
    rect.x = _x; rect.y = _y;
};
void Block::render(SDL_Renderer* _renderer){
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
};