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

bool Controller::init()
{
    if(!Layer::init())
        return false;
    initItems();
    initListener();
    initScheduler();
    return true;
}


void Controller::initListener()
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


void Controller::initItems()
{
    GET_ORI_VIS;
    button = Sprite::create("res/Controller/centerButton.png");
    button -> setPosition(SCREEN_CENTER);
    button -> setTag(1);
    button -> setVisible(false);
    button -> setScale(0.5);
    this -> addChild(button);
}


void Controller::initScheduler()
{
    initScheduleToCheckTheMovementDirection();
    Director::getInstance()->getScheduler()->schedule(scheduleToCheckTheMovementDirection, this, 0.01, kRepeatForever, 0, true, "checkDirection");
}


void Controller::initTouchBeginForDirectionController()
{
    begin = [this] (Touch* t, Event* e)
    {
        GET_ORI_VIS;
        if(t -> getLocation().x < visiableSize.width/2 + origin.x)
        {
            if(originalTouchPosition.x !=0 || originalTouchPosition.y !=0)
                return true;;
            button -> setPosition(t -> getLocation());
            originalTouchPosition . set(t -> getLocation());
            button -> setVisible(true);
            return true;
        }
        return false;
    };
}


void Controller::initTouchMovedForDirectionController()
{
    moved = [this](Touch* t, Event* e)
    {
        float dis = originalTouchPosition . getDistance(t -> getLocation());
        if(dis < 30)
        {
            button -> setPosition(t -> getLocation());
            mutex.lock();
            direction = Vec2(t -> getLocation().x - originalTouchPosition.x, t -> getLocation().y - originalTouchPosition.y);
            mutex.unlock();
            return;
        }
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


void Controller::initTouchEndedForDirectionController()
{
    ended = [this](Touch* t, Event* e)
    {
        GET_ORI_VIS;
        bool endedFromTheEdge = t -> getLocation().x < origin.x + 2 || t -> getLocation().y < origin.y + 2;
        if(endedFromTheEdge)
            return;
        button -> setVisible(false);
        originalTouchPosition.x = 0;
        originalTouchPosition.y = 0;
        mutex.lock();
        direction = Vec2(0, 0);
        mutex.unlock();
    };
}


void Controller::initScheduleToCheckTheMovementDirection()
{
    scheduleToCheckTheMovementDirection = [this](float){
        mutex.lock();
        if(direction.x != 0 && direction.y != 0)
        {
            auto parent = (GameScene*)this -> getParent();
            Movement::move(direction, parent, 1);
        }
        mutex.unlock();
    };
}



