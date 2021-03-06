#include "Map.hpp"
#include "Object.hpp"
#include "Player.hpp"
#include "Ground.hpp"
#include "TextureManager.hpp"
#include "ObjectManager.hpp"

void Map::loadMap(const char* _path) {
    std::ifstream file(_path);
    std::string line;

    int row = 0;
    while(getline(file, line)) {
        int lineSize = line.size();
        for(int i=0; i<lineSize; i++) {
            data[row][i] = line[i] - '0';
        }
        row++;
    }

    file.close();
}

void Map::renderMap(SDL_Renderer* _renderer) {
    for(int i=0; i<20; i++){
        for(int j=0; j<15; j++){
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