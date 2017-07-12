//
//  Controller.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#ifndef Controller_hpp
#define Controller_hpp


class ControllerLayer: public cocos2d::Layer
{
public:
    CREATE_FUNC(ControllerLayer);
    virtual bool init();
protected:
    void initScheduleToCheckTheMovementDirectionForHunter();
    void initScheduleToCheckTheMovementDirectionForSnake();
    std::function<void(float)> scheduleToCheckTheMovementDirection;
private:
    void initListener();
    void initItems();
    void initTouchBeginForDirectionController();
    void initTouchMovedForDirectionController();
    void initTouchEndedForDirectionController();
    
    
    std::function<bool(cocos2d::Touch*, cocos2d::Event*)> begin;
    std::function<void(cocos2d::Touch*, cocos2d::Event*)> moved;
    std::function<void(cocos2d::Touch*, cocos2d::Event*)> ended;
    cocos2d::EventListenerTouchOneByOne* listener;
    cocos2d::Sprite* button;
    cocos2d::Sprite* background;
    cocos2d::Point originalTouchPosition;
    cocos2d::Vec2 direction;
    std::mutex mutex;
};


#endif /* Controller_hpp */
