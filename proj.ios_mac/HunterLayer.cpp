//
//  HunterLayer.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/10/17.
//
//

#include "HunterLayer.hpp"
#include "Defines.h"
#include "Ship.hpp"
USING_NS_CC;

bool HunterLayer::init()
{
    if(!Layer::init())
        return false;
    
    initItems();
    return true;
}


void HunterLayer::initItems()
{
    GET_ORI_VIS;
    role = Ship::create(0);
    this -> addChild(role);
}


void HunterLayer::setDirection(Vec2 direction)
{
    auto standardVec = Vec2(0, 1);
    role -> setRotation(standardVec.getAngle(Vec2(direction.x * -1, direction.y)) * 57.3);
}
