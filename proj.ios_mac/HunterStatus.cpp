//
//  HunterStatus.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/12/17.
//
//

#include "HunterStatus.hpp"
#include "Defines.h"
#include <thread>
#include <unistd.h>
USING_NS_CC;
using namespace std;


HunterStatus* HunterStatus::create(Point pos, Vec2 dir)
{
    HunterStatus* ptr = new HunterStatus(pos, dir);
    if(ptr -> init())
    {
        ptr -> autorelease();
        return ptr;
    }
    delete ptr;
    ptr = NULL;
    return NULL;
}

HunterStatus::HunterStatus(Point pos, Vec2 dir)
{
    mutex.lock();
    position.set(pos);
    direction.set(dir);
    mutex.unlock();
}

void HunterStatus::setPosition(Point pos)
{
    mutex.lock();
    position.set(pos);
    mutex.unlock();
}

Point HunterStatus::getPosition()
{
    Point temp;
    mutex.lock();
    temp.set(position);
    mutex.unlock();
    return temp;
}

void HunterStatus::setDirection(Vec2 dir)
{
    mutex.lock();
    direction.set(dir);
    mutex.unlock();
}

Vec2 HunterStatus::getDirection()
{
    Vec2 temp;
    mutex.lock();
    temp.set(direction);
    mutex.unlock();
    return temp;
}

bool HunterStatus::init()
{
    if(!Node::init())
        return false;
    return true;
}


void HunterStatus::startRefreshingStatus()
{
    thread refresh(&HunterStatus::refreshFunction, this);
    refresh.detach();
}

void HunterStatus::refreshOnce()
{
    mutex.lock();
    position.add(direction);
    mutex.unlock();
}

void HunterStatus::refreshFunction()
{
    while (true) {
        refreshOnce();
        usleep(10000);
    }
}

void HunterStatus::copy(HunterStatus hunter)
{
    setPosition(hunter.getPosition());
    setDirection(hunter.getDirection());
}

