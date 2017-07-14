//
//  backgroundLayer.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/9/17.
//
//  Do not delete me!
//  Do not change me!!!

#include "BackgroundLayer.hpp"
#include "Defines.h"
#define MAX_X 1000
#define MAX_Y 1000
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
    this -> startPoint.set(p);
}

bool BackgroundLayer::init()
{
    if(!Layer::init())
        return true;
    if(!(startPoint.x <= MAX_X && startPoint.x >= MIN_X\
         && startPoint.y <= MAX_Y && startPoint.y >= MIN_Y))
        return false;
    initItems();
    return true;
}

void BackgroundLayer::initItems()
{
    GET_ORI_VIS;
    for(int i = 0; i < PIXL_NUM; ++i)
    {
        for(int j = 0; j< PIXL_NUM; ++j)
        {
            backgroundPicture[i][j] = CCSprite::createWithTexture(CCTextureCache::sharedTextureCache() -> textureForKey("res/GameScene/backgroundReal.png"));
            backgroundPicture[i][j] -> setAnchorPoint(Vec2(0, 0));
            backgroundPicture[i][j] -> setPosition(origin.x + visiableSize.width/2 + i * backgroundPicture[0][0] -> getContentSize().width + i * (-1), \
                                                   origin.y + visiableSize.height/2 + j * backgroundPicture[0][0] -> getContentSize().height + j * (-1));
            currentPosition[i][j] = Point(backgroundPicture[i][j] -> getPosition());
            this -> addChild(backgroundPicture[i][j]);
        }
    }
    setStartPoint();
    
}

bool BackgroundLayer::move(Vec2 direction)
{
    for(int i = 0; i < PIXL_NUM; ++i)
    {
        for(int j = 0; j< PIXL_NUM; ++j)
        {
            float width = backgroundPicture[0][0] -> getContentSize().width;
            Vec2 realDir = Vec2(direction.x * (width*PIXL_NUM/3800)/1.5, direction.y * (width*PIXL_NUM/3800)/1.5);
            currentPosition[i][j].add(realDir);
            backgroundPicture[i][j] -> setPosition(currentPosition[i][j]);
        }
    }
    return true;
}

void BackgroundLayer::moveToo(Vec2 direction)
{
    for(int i = 0; i < PIXL_NUM; ++i)
    {
        for(int j = 0; j< PIXL_NUM; ++j)
        {
            currentPosition[i][j].add(direction);
            backgroundPicture[i][j] -> setPosition(currentPosition[i][j]);
        }
    }
}

void BackgroundLayer::setStartPoint()
{
    float x = startPoint.x;
    float y = startPoint.y;
    float width = backgroundPicture[0][0] -> getContentSize().width;
    float height = backgroundPicture[0][0] -> getContentSize().height;
    moveToo(Vec2(-width*PIXL_NUM * x/5674.5 , -height*PIXL_NUM * y/5809.29));
}




