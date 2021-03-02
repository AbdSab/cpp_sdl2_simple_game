/**
* Input Class
**/
#pragma once

#include <SDL2/SDL.h>

#define INPUT_UP 0
#define INPUT_RIGHT 1
#define INPUT_DOWN 2
#define INPUT_LEFT 3

class Input {
public:
    static bool arrow[4];
    static void update(SDL_Event event);
};