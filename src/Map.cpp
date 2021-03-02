#include "Map.hpp"
#include <vector>
#include <Object.hpp>
#include <Player.hpp>
#include <Ground.hpp>
#include <TextureManager.hpp>
#include <ObjectManager.hpp>

void Map::loadMap(SDL_Renderer* _renderer) {
    int _data[5][5] = {{0,0,0,0,0}, {2,0,0,0,2}, {2,0,0,2,2}, {2,2,1,0,2}, {2,2,2,2,2}};
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            data[i][j] = _data[i][j];
            switch(data[i][j]) {
                case ID_PLAYER: {
                    SDL_Texture* texture = TextureManager::getTexture("player");
                    Player* player = new Player(j*TILE_SIZE, i*TILE_SIZE, texture);
                    player->setDynamic(true);
                    ObjectManager::addObject(player);
                    break;
                }
                case ID_GROUND: {
                    SDL_Texture* texture = TextureManager::getTexture("ground");
                    Ground* ground = new Ground(j*TILE_SIZE, i*TILE_SIZE, texture);
                    ObjectManager::addObject(ground);
                    break;
                }
            }
        }
    }
}

int Map::getIdByPosition(int _x, int _y) {
    return data[_y][_x];
}