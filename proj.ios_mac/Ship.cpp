//
//  Ship.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/12/17.
//
//

#include "Ship.hpp"
#include "Defines.h"
USING_NS_CC;


Ship* Ship::create(unsigned level)
{
    Ship* ptr = new Ship(level);
    if(ptr -> init())
    {
        ptr -> autorelease();
        return ptr;
    }
    delete ptr;
    ptr = NULL;
    return ptr;
}

Ship::Ship(unsigned level)
{
    this -> level = level;
}

bool Ship::init()
{
    if(!Sprite::init())
        return false;
    GET_ORI_VIS;
    this -> setTexture("res/Roles/level1Ship.png");
    this -> setScale(visiableSize.width * visiableSize.height /324507.5);
    this -> setPosition(SCREEN_CENTER);
    return true;
}

void Ship::levelUp()
{
    
}

void Ship::setDirection(Vec2 direction)
{
    auto standardVec = Vec2(0, 1);
    this -> setRotation(standardVec.getAngle(Vec2(direction.x * -1, direction.y)) * 57.3);
}
