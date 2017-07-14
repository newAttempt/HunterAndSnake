//
//  Ship.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/12/17.
//
//

#ifndef Ship_hpp
#define Ship_hpp

class Ship: public cocos2d::Sprite
{
public:
    static Ship* create(unsigned);
    Ship(unsigned);
    virtual bool init();
    void levelUp();
    void setDirection(cocos2d::Vec2);
private:
    unsigned level;
};

#endif /* Ship_hpp */
