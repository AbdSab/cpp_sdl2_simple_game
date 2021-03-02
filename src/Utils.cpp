#include "Utils.hpp"
#include "Map.hpp"
#include <iostream>

Map* Utils::map;

int Utils::getMapIdByPosition(int _x, int _y) {
    int x = _x / TILE_SIZE;
    int y = _y / TILE_SIZE;
    return map->getIdByPosition(x, y);
}