//
//  HunterLayer.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/10/17.
//
//

#include "HunterLayer.hpp"
#include "Defines.h"
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
    role = Sprite::Sprite::createWithTexture(CCTextureCache::sharedTextureCache() -> textureForKey("res/Roles/hunter.png"));
    role -> setScale(5);
    role -> setPosition(SCREEN_CENTER);
    this -> addChild(role);
}


void HunterLayer::setDirection(Vec2 direction)
{
    auto standardVec = Vec2(0, 1);
    role -> setRotation(standardVec.getAngle(Vec2(direction.x * -1, direction.y)) * 57.3);
}
