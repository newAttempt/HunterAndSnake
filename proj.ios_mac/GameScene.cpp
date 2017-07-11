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
#include "HunterLayer.hpp"
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
    auto controlLayer = Controller::create();
    auto hunterLayer = HunterLayer::create();
    this -> addChild(background, 0);
    this -> addChild(hunterLayer, 2);
    this -> addChild(controlLayer, 10);
    background -> setTag(BACKGROUND_LAYER);
    hunterLayer -> setTag(HUNTER_LAYER);
}
