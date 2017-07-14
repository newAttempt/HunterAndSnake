//
//  Movement.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/9/17.
//
//

#ifndef Movement_hpp
#define Movement_hpp
#include "HunterStatus.hpp"

class Movement
{
public:
    static void init(cocos2d::Scene*);
    static void moveHunter(cocos2d::Vec2, cocos2d::Scene* gameScene);
    static void moveSnake(cocos2d::Vec2, cocos2d::Scene* gameScene);
private:
    static HunterStatus* mainRoleStatus;
};

#endif /* Movement_hpp */
