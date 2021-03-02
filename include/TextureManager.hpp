#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <unordered_map>

#define TILE_SIZE 32

/**
* Texture Manager Class
**/
class TextureManager {
public:
    static std::unordered_map<std::string, SDL_Texture*> textures;
    static void loadTexture(SDL_Renderer* renderer, std::string name, const char* path);
    static SDL_Texture* getTexture(std::string name);
    static void clear();
};