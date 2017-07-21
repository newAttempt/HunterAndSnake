//
//  ManuScene.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#include "GameScene.hpp"
#include "Defines.h"
#include "ControllerForHunter.hpp"
#include "BackgroundLayer.hpp"
#include "HunterLayer.hpp"
#include "ControllerForSnake.hpp"
#include "HunterStatus.hpp"
#include "HuntersSet.hpp"
#include "Movement.hpp"
#include "Client.hpp"
#include <unistd.h>
USING_NS_CC;


GameScene* GameScene::create(int sceneType)
{
    GameScene* ptr = new GameScene(sceneType);
    if(ptr -> init())
    {
        ptr -> autorelease();
        return ptr;
    }
    delete ptr;
    ptr = NULL;
    return ptr;
}


GameScene::GameScene(int sceneType)
{
    this -> sceneType = sceneType;
}


bool GameScene::init()
{
    if(!Scene::init())
        return false;
    if(sceneType == HUNTER_SCENE_TYPE)
        initItemsForHunter();
    else
        initItemsForSnake();
    Movement::init(this);
    return true;
}


void GameScene::initItemsForHunter()
{
    auto background = BackgroundLayer::create(Point(16, 21));
    auto controlLayer = ControllerForHunter::create();
    auto hunterLayer = HunterLayer::create();
    this -> addChild(background, 0);
    this -> addChild(hunterLayer, 2);
    this -> addChild(controlLayer, 3);
    background -> setTag(BACKGROUND_LAYER);
    hunterLayer -> setTag(HUNTER_LAYER);
    auto client = Client::create();
}


void GameScene::initItemsForSnake()
{
    auto background = BackgroundLayer::create(Point(1000, 1000));
    auto controlLayer = ControllerForSnake::create();
    this -> addChild(background, 0);
    this -> addChild(controlLayer, 10);
    background -> setTag(BACKGROUND_LAYER);
}

