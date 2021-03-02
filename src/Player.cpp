#include "Player.hpp"
#include "Input.hpp"
#include "Utils.hpp"
#include "Map.hpp"
#include <iostream>


Player::Player(int _x, int _y, SDL_Texture* _texture) : Object(_x, _y, _texture){
    gravity = 4;
    jump = 0;
    atGround = false;
}

void Player::update() {
    int bottomId = Utils::getMapIdByPosition(rect.x, rect.y + TILE_SIZE);
    atGround = bottomId == ID_GROUND;
    if( !atGround && jump == 0) {
        rect.y += gravity;
    }
    if(jump > 0) {
        jump--;
        rect.y -= 4;
    }
    if(Input::arrow[INPUT_UP] && jump == 0 && atGround) {
        jump = 8;
    }
    if(Input::arrow[INPUT_RIGHT]) {
        if(Utils::getMapIdByPosition(rect.x + TILE_SIZE, rect.y) != ID_GROUND) rect.x++;
    }else if(Input::arrow[INPUT_LEFT]) {
        if(Utils::getMapIdByPosition(rect.x, rect.y) != ID_GROUND) rect.x--;
    }
}