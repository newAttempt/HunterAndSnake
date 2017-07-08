//
//  Controller.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#include "Controller.hpp"
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
    return true;
}


void Controller::initListener()
{
    listener = EventListenerTouchOneByOne::create();
    auto begin = [this] (Touch* t, Event* e)
    {
        GET_ORI_VIS;
        if(t -> getLocation().x < visiableSize.width/2 + origin.x && t -> getLocation().x > origin.x + 10)
        {
            button -> setPosition(t -> getLocation());
            originalTouchPosition . set(t -> getLocation());
            button -> setVisible(true);
            return true;
        }
        return false;
    };
    auto moved = [this](Touch* t, Event* e)
    {
        float dis = originalTouchPosition . getDistance(t -> getLocation());
        if(dis < 30)
        {
            button -> setPosition(t -> getLocation());
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
        
    };
    auto ended = [this](Touch* t, Event* e)
    {
        button -> setVisible(false);
    };
    
    listener -> onTouchBegan = begin;
    listener -> onTouchMoved = moved;
    listener -> onTouchEnded = ended;
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}


void Controller::initItems()
{
    GET_ORI_VIS;
    button = Sprite::create("res/controller.png");
    button -> setPosition(SCR_CEN);
    button -> setTag(1);
    button -> setVisible(false);
    button -> setScale(0.5);
    this -> addChild(button);
}




