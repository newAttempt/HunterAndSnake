//
//  Movement.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/9/17.
//
//

#include "Movement.hpp"
#include "BackgroundLayer.hpp"
#include "HunterLayer.hpp"
#include "Defines.h"
#include <math.h>
USING_NS_CC;

void Movement::moveHunter(Vec2 direction, Scene* gameScene, int times)
{
    auto background = (BackgroundLayer*) gameScene -> getChildByTag(BACKGROUND_LAYER);
    auto hunter = (HunterLayer*) gameScene -> getChildByTag(HUNTER_LAYER);
    background -> move(Vec2(direction.x * -1, direction.y * -1), times);
    hunter -> setDirection(direction);
}


void Movement::moveSnake(Vec2 direction, Scene* gameScene, int times)
{
    auto background = (BackgroundLayer*) gameScene -> getChildByTag(BACKGROUND_LAYER);
    background -> move(Vec2(direction.x * -1, direction.y * -1), times);
}
