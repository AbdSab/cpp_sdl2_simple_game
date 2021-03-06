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
    static int delay;
    static bool canCheck;
    static bool arrow[4];
    static bool checkDelayedPress(int keyCode);
    static void update(SDL_Event event);
};