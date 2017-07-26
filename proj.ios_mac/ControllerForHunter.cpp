//
//  ControllerForHunter.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/10/17.
//
//

#include "ControllerForHunter.hpp"
USING_NS_CC;

bool ControllerForHunter::init()
{
    if(!ControllerLayer::init())
        return false;
    initScheduler();
    return true;
}


void ControllerForHunter::initScheduler()
{
    initScheduleToCheckTheMovementDirectionForHunter();
    Director::getInstance()->getScheduler()->schedule(scheduleToCheckTheMovementDirection, this, 0.02, kRepeatForever, 0, true, "checkDirection");
}



