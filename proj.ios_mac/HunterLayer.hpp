//
//  HunterLayer.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/10/17.
//
//

#ifndef HunterLayer_hpp
#define HunterLayer_hpp
#include "Ship.hpp"

class HunterLayer : public cocos2d::Layer
{
public:
    CREATE_FUNC(HunterLayer);
    virtual bool init();
    
    void setDirection(cocos2d::Vec2 direction);
private:
    void initItems();
    Ship* role;
    
};

#endif /* HunterLayer_hpp */
