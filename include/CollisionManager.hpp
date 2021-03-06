#pragma once

#include<vector>

class CollisionManager {
private:
    Object* src;
    std::vector<Object*> others;

public:
    update() {
        for(Object* dest : others) {
            //if(dest->getX)
        }
    }
}