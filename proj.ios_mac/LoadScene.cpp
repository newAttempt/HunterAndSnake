//
//  LoadScene.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/11/17.
//
//

#include "LoadScene.hpp"
#include "GameScene.hpp"
#include "Defines.h"
USING_NS_CC;

LoadScene* LoadScene::create(int gameSceneType)
{
    LoadScene* ptr = new LoadScene(gameSceneType);
    if(ptr -> init())
    {
        ptr -> autorelease();
        return ptr;
    }
    delete ptr;
    ptr = NULL;
    return ptr;
}

LoadScene::LoadScene(int gameSceneType)
{
    this -> gameSceneType = gameSceneType;
}

bool LoadScene::init()
{
    if(!Scene::init())
        return false;
    initItems();
    
    pictureNumTotal = 4;
    pictureNumCurrent = 0;
    initCallBackFunc();
    CCTextureCache::sharedTextureCache()->addImageAsync("res/GameScene/backgroundReal.png", loadCallBack);
    CCTextureCache::sharedTextureCache()->addImageAsync("res/Controller/controllerButton.png", loadCallBack);
    CCTextureCache::sharedTextureCache()->addImageAsync("res/Roles/hunter.png", loadCallBack);
    CCTextureCache::sharedTextureCache()->addImageAsync("res/Controller/greyBackingWithArrows.png", loadCallBack);
    return true;
}


void LoadScene::initCallBackFunc()
{
    loadCallBack = [this](Texture2D* t){
        mutex.lock();
        GET_ORI_VIS;
        ++pictureNumCurrent;
        loadingBlue -> setScale(visiableSize.width/loadingBlue -> getContentSize().width * 0.6 * pictureNumCurrent/pictureNumTotal, loadingBlue -> getScaleY());
        std::string s = "Loading " + std::string(t -> getStringForFormat());
        loadingLabel -> setString(s);
        if(pictureNumCurrent >= pictureNumTotal)
        {
            loadingLabel -> setString("Loading finished.");
            auto scene = GameScene::create(gameSceneType);
            Director::getInstance()->replaceScene(scene);
        }
        mutex.unlock();
    };
}


void LoadScene::initItems()
{
    GET_ORI_VIS;
    background = Sprite::create("res/LoadingElements/loadingBackground.png");
    background -> setAnchorPoint(Vec2(0, 0));
    background -> setPosition(Vec2(origin.x, origin.y));
    this -> addChild(background, 0);
    shipAndBall = Sprite::create("res/LoadingElements/loadingShipAndBall.png");
    shipAndBall -> setAnchorPoint(Vec2(0.5, 0));
    shipAndBall -> setPosition(origin.x + visiableSize.width/2, origin.y);
    shipAndBall -> setScale(visiableSize.width/(shipAndBall->getContentSize().width));
    this -> addChild(shipAndBall, 1);
    loadingBlue = Sprite::create("res/LoadingElements/loadingBlue.png");
    loadingBlue -> setAnchorPoint(Vec2(0, 0.5));
    loadingBlue -> setScale(visiableSize.height* 0.03/ loadingBlue -> getContentSize().height);
    loadingBlue -> setPosition(origin.x + visiableSize.width/2 - visiableSize.width * 0.315, origin.y + visiableSize.height * 0.147);
    this -> addChild(loadingBlue, 3);
    loadingLabel = Label::createWithSystemFont("Loading...  ", "", 18);
    loadingLabel -> setPosition(origin.x + visiableSize.width/2, origin.y + visiableSize.height * 0.3);
    this -> addChild(loadingLabel, 3);
    
}


