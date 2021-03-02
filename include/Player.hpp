#pragma once
#include "Object.hpp"
#include "Utils.hpp"

/**
* Player Class
**/
class Player: public Object {
private:
    int gravity;
    int jump;
    bool atGround;
public:
    Player(int _x, int _y, SDL_Texture* _texture);
    void update();
};