#include <SDL2/SDL.h>
#include "Input.hpp"

bool Input::arrow[4] = {};

void Input::update(SDL_Event event) {
    if(event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym) {
            case SDLK_UP: arrow[INPUT_UP] = true; break;
            case SDLK_RIGHT: arrow[INPUT_RIGHT] = true; break;
            case SDLK_DOWN: arrow[INPUT_DOWN] = true; break;
            case SDLK_LEFT: arrow[INPUT_LEFT] = true; break;
        }
    }else if(event.type == SDL_KEYUP) {
        switch(event.key.keysym.sym) {
            case SDLK_UP: arrow[INPUT_UP] = false; break;
            case SDLK_RIGHT: arrow[INPUT_RIGHT] = false; break;
            case SDLK_DOWN: arrow[INPUT_DOWN] = false; break;
            case SDLK_LEFT: arrow[INPUT_LEFT] = false; break;
        }
    }
}