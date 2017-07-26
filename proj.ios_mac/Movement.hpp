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
#include "WebManager.hpp"

class Movement
{
public:
    static void init(cocos2d::Scene*);
    static void moveHunter(cocos2d::Vec2, cocos2d::Scene* gameScene);
    static void moveSnake(cocos2d::Vec2, cocos2d::Scene* gameScene);
private:
    static HunterStatus* mainRoleStatus;
    static std::string id;
    static WebManager *webManager;
};

#endif /* Movement_hpp */
