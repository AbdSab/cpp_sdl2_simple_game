#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <Object.hpp>

#define ID_EMPTY 0
#define ID_PLAYER 1
#define ID_GROUND 2

/**
* Map Class
**/
class Map {
private:
    int data[5][5];
public:
    void loadMap(SDL_Renderer* _renderer);
    int getIdByPosition(int _x, int _y);
};