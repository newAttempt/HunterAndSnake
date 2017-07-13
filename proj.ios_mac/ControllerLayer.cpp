//
//  Controller.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#include "ControllerLayer.hpp"
#include "GameScene.hpp"
#include "Movement.hpp"
#include "cocos2d.h"
#include "Defines.h"
#include <math.h>
USING_NS_CC;
using namespace std;

bool ControllerLayer::init()
{
    if(!Layer::init())
        return false;
    initItems();
    initListener();
    Movement::init();
    return true;
}


void ControllerLayer::initListener()
{
    initTouchBeginForDirectionController();
    initTouchEndedForDirectionController();
    initTouchMovedForDirectionController();
    listener = EventListenerTouchOneByOne::create();
    listener -> onTouchBegan = begin;
    listener -> onTouchMoved = moved;
    listener -> onTouchEnded = ended;
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}


void ControllerLayer::initItems()
{
    /*
    GET_ORI_VIS;
    button = Sprite::Sprite::createWithTexture(CCTextureCache::sharedTextureCache() -> textureForKey("res/Controller/centerButton.png"));
    button -> setPosition(SCREEN_CENTER);
    button -> setTag(1);
    button -> setVisible(false);
    button -> setScale(0.5);
    this -> addChild(button);
     */ //Modified by Zeyong Shan       => upload the new ControllerButton and make new screen adapting.
    GET_ORI_VIS;
    button = Sprite::createWithTexture(CCTextureCache::sharedTextureCache() -> textureForKey("res/Controller/controllerButton.png"));
    button -> setPosition(SCREEN_CENTER);
    button -> setVisible(false);
    button -> setScale(visiableSize.height * visiableSize.width/1298030);
    this -> addChild(button, 1);
    
    background = Sprite::createWithTexture(CCTextureCache::sharedTextureCache() -> textureForKey("res/Controller/greyBackingWithArrows.png"));
    background -> setPosition(SCREEN_CENTER);
    background -> setVisible(false);
    background -> setScale(70/background -> getContentSize().width);
    this -> addChild(background, 0);
}


void ControllerLayer::initTouchBeginForDirectionController()
{
    begin = [this] (Touch* t, Event* e)
    {
        GET_ORI_VIS;
        if(t -> getLocation().x < visiableSize.width/2 + origin.x)
        {
            if(originalTouchPosition.x !=0 || originalTouchPosition.y !=0)
                return true;;
            button -> setPosition(t -> getLocation());
            background -> setPosition(t -> getLocation());
            originalTouchPosition . set(t -> getLocation());
            button -> setVisible(true);
            background -> setVisible(true);
            return true;
        }
        return false;
    };
}


void ControllerLayer::initTouchMovedForDirectionController()
{
    moved = [this](Touch* t, Event* e)
    {
        float dis = originalTouchPosition . getDistance(t -> getLocation());
        float X = abs(t -> getLocation().x - originalTouchPosition . x);
        float Y = abs(t -> getLocation().y - originalTouchPosition . y);
        float x = (30 * X) / dis;
        float y = (30 * Y) / dis;
        if(t -> getLocation().x < originalTouchPosition . x)
            x *= -1;
        if(t -> getLocation().y < originalTouchPosition . y)
            y *= -1;
        button -> setPosition(originalTouchPosition.x + x, originalTouchPosition . y + y);
        
        mutex.lock();
        direction = Vec2(x, y);
        mutex.unlock();
    };
}


void ControllerLayer::initTouchEndedForDirectionController()
{
    ended = [this](Touch* t, Event* e)
    {
        GET_ORI_VIS;
        bool endedFromTheEdge = t -> getLocation().x < origin.x + 2 || t -> getLocation().y < origin.y + 2;
        if(endedFromTheEdge)
            return;
        button -> setVisible(false);
        background -> setVisible(false);
        originalTouchPosition.x = 0;
        originalTouchPosition.y = 0;
        mutex.lock();
        direction = Vec2(0, 0);
        mutex.unlock();
    };
}


void ControllerLayer::initScheduleToCheckTheMovementDirectionForHunter()
{
    scheduleToCheckTheMovementDirection = [this](float){
        mutex.lock();
        if(direction.x != 0 && direction.y != 0)
        {
            auto parent = (GameScene*)this -> getParent();
            Movement::moveHunter(direction, parent);
        }
        mutex.unlock();
    };
}

void ControllerLayer::initScheduleToCheckTheMovementDirectionForSnake()
{
    scheduleToCheckTheMovementDirection = [this](float){
        mutex.lock();
        if(direction.x != 0 && direction.y != 0)
        {
            auto parent = (GameScene*)this -> getParent();
            Movement::moveSnake(direction, parent);
        }
        mutex.unlock();
    };
}
