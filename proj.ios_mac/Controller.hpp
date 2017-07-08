//
//  Controller.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#ifndef Controller_hpp
#define Controller_hpp


class Controller: public cocos2d::Layer
{
public:
    CREATE_FUNC(Controller);
    virtual bool init();
private:
    void initListener();
    void initItems();
    
    cocos2d::EventListenerTouchOneByOne* listener;
    cocos2d::Sprite* button;
    cocos2d::Point originalTouchPosition;
};

#endif /* Controller_hpp */
