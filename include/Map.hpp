#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <fstream>
#include <Object.hpp>

#define ID_EMPTY 0
#define ID_PLAYER 1
#define ID_GROUND 2

/**
* Map Class
**/
class Map {
private:
    int data[20][15];
public:
    void loadMap(const char* _path);
    void renderMap(SDL_Renderer* _renderer);
    int getIdByPosition(int _x, int _y);
};