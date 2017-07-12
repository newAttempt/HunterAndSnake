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

Point Movement::p;

void Movement::init()
{
    p.set(0, 0);
}

void Movement::moveHunter(Vec2 direction, Scene* gameScene)
{
    auto background = (BackgroundLayer*) gameScene -> getChildByTag(BACKGROUND_LAYER);
    auto hunter = (HunterLayer*) gameScene -> getChildByTag(HUNTER_LAYER);
    background -> move(Vec2(direction.x * -1 * 0.05, direction.y * -1 * 0.05));
    hunter -> setDirection(direction);
    p.add(Vec2(direction.x * 0.05, direction.y * 0.05));
}


void Movement::moveSnake(Vec2 direction, Scene* gameScene)
{
    auto background = (BackgroundLayer*) gameScene -> getChildByTag(BACKGROUND_LAYER);
    background -> move(Vec2(direction.x * -1 * 0.05, direction.y * -1 * 0.05));
}
//5693.348145, 5830.480957   Iphone 5
//5691.214355, 5809.899902   Iphone 7 Plus
//5680.570801, 5817.456543   Ipad Pro 12.9inch
