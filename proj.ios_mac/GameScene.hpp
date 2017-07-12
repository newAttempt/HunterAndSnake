//
//  ManuScene.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp
#include "cocos2d.h"

class GameScene: public cocos2d::Scene
{
public:
    static GameScene* create(int sceneType);
    GameScene(int sceneType);
    virtual bool init();
private:
    void initItemsForHunter();
    void initItemsForSnake();
    
    int sceneType;
};


#endif /* ManuScene_hpp */
