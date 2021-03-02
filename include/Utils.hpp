#pragma once
#define TILE_SIZE 32

/**
* Utils Class
**/
class Map;
class Utils {
public:
    static Map* map;
    static int getMapIdByPosition(int _x, int _y);
};