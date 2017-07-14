//
//  HunterStatus.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/12/17.
//
//

#ifndef HunterStatus_hpp
#define HunterStatus_hpp

class HunterStatus: public cocos2d::Node
{
public:
    static HunterStatus* create(cocos2d::Point position, cocos2d::Vec2 direction);
    virtual bool init();
    HunterStatus(cocos2d::Point position, cocos2d::Vec2 direction);
    void setPosition(cocos2d::Point position);
    cocos2d::Point getPosition();
    void setDirection(cocos2d::Vec2 direction);
    cocos2d::Vec2 getDirection();
    void copy(HunterStatus);
    void startRefreshingStatus();
private:
    cocos2d::Point position;
    cocos2d::Vec2  direction;
    std:: mutex    mutex;
    void refreshFunction();
    void refreshOnce();
};


#endif /* HunterStatus_hpp */
