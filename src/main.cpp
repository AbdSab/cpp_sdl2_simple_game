#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <unordered_map> 

#define TILE_SIZE 32

#include "Input.hpp"
#include "TextureManager.hpp"
#include "Utils.hpp"
#include "Object.hpp"
#include "ObjectManager.hpp"
#include "Player.hpp"
#include "Ground.hpp"
#include "Map.hpp"

/**
* Main
**/
int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        std::cout << "error initializing SDL:" <<  SDL_GetError() << std::endl; 
    } 
    SDL_Window* window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 32 * 5, 32 * 5, 0); 
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); 

    /** Load resources **/
    TextureManager::loadTexture(renderer, "player", "res/sprites/brick.png");
    TextureManager::loadTexture(renderer, "ground", "res/sprites/ground.png");

    /** Create map **/
    Map map;
    map.loadMap(renderer);
    Utils::map = &map;

    bool running = true;

    while (running) { 
        SDL_Event event; 
        while (SDL_PollEvent(&event)) { 
            switch (event.type) { 
                case SDL_QUIT:
                    running = false; 
                    break;
            } 
            Input::update(event);
        }
        SDL_RenderClear(renderer); 

        ObjectManager::update(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / 60);
    }

    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window); 
    //TextureManager::clear();

	return 1;
}