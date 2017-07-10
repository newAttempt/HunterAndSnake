//
//  backgroundLayer.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/9/17.
//
//

#include "BackgroundLayer.hpp"
#include "Defines.h"
#define MAX_X 100
#define MAX_Y 100
#define MIN_X 0
#define MIN_Y 0
USING_NS_CC;

BackgroundLayer* BackgroundLayer::create(Point p)
{
    BackgroundLayer* ptr = new BackgroundLayer(p);
    if(ptr -> init())
    {
        ptr -> autorelease();
        return ptr;
    }
    delete ptr;
    ptr = NULL;
    return ptr;
}

BackgroundLayer:: BackgroundLayer(Point p)
{
    this -> currentPosition.set(p);
}

bool BackgroundLayer::init()
{
    if(!Layer::init())
        return true;
    if(!(currentPosition.x < MAX_X && currentPosition.x > MIN_X\
         && currentPosition.y < MAX_Y && currentPosition.y > MIN_Y))
        return false;
    initItems();
    return true;
}

void BackgroundLayer::initItems()
{
    GET_ORI_VIS;
    backgroundPicture = Sprite::create("res/GameScene/background.png");
    backgroundPicture -> setScale(10);
    backgroundPicture -> setAnchorPoint(Vec2(currentPosition.x/100, currentPosition.y/100));
    backgroundPicture -> setPosition(SCREEN_CENTER);
    currentPosition = Point(SCREEN_CENTER);
    this -> addChild(backgroundPicture);
}

bool BackgroundLayer::move(Vec2 direction, unsigned times)
{
    for(int x = 0; x<times; ++x)
    {
        currentPosition.add(direction*0.05);
        backgroundPicture -> setPosition(currentPosition);
    }
    log("move!!!!!!!!!!\n\n\n\n\n");
    return true;
}








