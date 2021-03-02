#include "TextureManager.hpp"

std::unordered_map<std::string, SDL_Texture*> TextureManager::textures;

void TextureManager::loadTexture(SDL_Renderer* renderer, std::string name, const char* path) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, path);
    if(texture == NULL) std::cout << "Error loading texture" << SDL_GetError() << std::endl;
    textures[name] = texture;
}

SDL_Texture* TextureManager::getTexture(std::string name) {
    return textures[name];
}

void TextureManager::clear() {
    for(auto& map : textures) SDL_DestroyTexture(map.second);
}