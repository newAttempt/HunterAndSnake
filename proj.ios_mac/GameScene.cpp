//
//  ManuScene.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#include "GameScene.hpp"
#include "Defines.h"
#include "ControllerLayer.hpp"
#include "BackgroundLayer.hpp"
USING_NS_CC;

bool GameScene::init()
{
    if(!Scene::init())
        return false;
    
    initItems();
    return true;
}


void GameScene::initItems()
{
    auto background = BackgroundLayer::create(Point(30, 30));
    auto ControlLayer = Controller::create();
    this -> addChild(background, 0);
    this -> addChild(ControlLayer, 1);
    background -> setTag(BACKGROUND);
}
