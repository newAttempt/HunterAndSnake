//
//  ControllerForSnake.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/10/17.
//
//

#include "ControllerForSnake.hpp"
USING_NS_CC;

bool ControllerForSnake::init()
{
    if(!ControllerLayer::init())
        return false;
    initScheduler();
    return true;
}

void ControllerForSnake::initScheduler()
{
    initScheduleToCheckTheMovementDirectionForSnake();
    Director::getInstance()->getScheduler()->schedule(scheduleToCheckTheMovementDirection, this, 0.01, kRepeatForever, 0, true, "checkDirection");
}


