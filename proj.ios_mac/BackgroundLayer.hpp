//
//  backgroundLayer.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/9/17.
//
//

#ifndef backgroundLayer_hpp
#define backgroundLayer_hpp

class BackgroundLayer: public cocos2d::Layer
{
public:
    static BackgroundLayer* create(cocos2d::Point);
    BackgroundLayer(cocos2d::Point);
    virtual bool init();
    
    bool move(cocos2d::Vec2, unsigned);
private:
    void initItems();
    
    cocos2d::Point currentPosition;
    cocos2d::Sprite* backgroundPicture;
};


#endif /* backgroundLayer_hpp */
