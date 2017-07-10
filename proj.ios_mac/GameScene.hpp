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
    CREATE_FUNC(GameScene);
    virtual bool init();
private:
    void initItems();
};


#endif /* ManuScene_hpp */
