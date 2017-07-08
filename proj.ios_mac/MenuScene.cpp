//
//  ManuScene.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#include "MenuScene.hpp"
#include "Defines.h"
#include "Controller.hpp"
USING_NS_CC;

bool MenuScene::init()
{
    if(!Scene::init())
        return false;
    
    GET_ORI_VIS;
    auto bow = Sprite::create("res/background.png");
    bow -> setScale(5);
    bow -> setPosition(SCR_CEN);
    this -> addChild(bow, 0);
    auto layer = Controller::create();
    this -> addChild(layer, 1);
    return true;
}
