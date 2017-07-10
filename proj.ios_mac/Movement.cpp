//
//  Movement.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/9/17.
//
//

#include "Movement.hpp"
#include "BackgroundLayer.hpp"
#include "Defines.h"
USING_NS_CC;

void Movement::move(Vec2 direction, Scene* gameScene, int times)
{
    auto background = (BackgroundLayer*) gameScene -> getChildByTag(BACKGROUND);
    background -> move(Vec2(direction.x * -1, direction.y * -1), times);
}
