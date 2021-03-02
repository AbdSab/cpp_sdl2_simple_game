#pragma once
#include <SDL2/SDL.h>

/**
* Gound Class
**/
class Ground : public Object{
public:
    Ground(int _x, int _y, SDL_Texture* _texture): Object(_x, _y, _texture) {};
};