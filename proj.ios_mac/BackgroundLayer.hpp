//
//  backgroundLayer.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/9/17.
//
//

#ifndef backgroundLayer_hpp
#define backgroundLayer_hpp
#define PIXL_NUM 6

class BackgroundLayer: public cocos2d::Layer
{
public:
    static BackgroundLayer* create(cocos2d::Point);
    BackgroundLayer(cocos2d::Point);
    virtual bool init();
    
    bool move(cocos2d::Vec2);
private:
    void initItems();
    void setStartPoint();
    void moveToo(cocos2d::Vec2 direction);
    
    cocos2d::Point currentPosition[PIXL_NUM][PIXL_NUM];
    cocos2d::Point startPoint;
    cocos2d::CCSprite* backgroundPicture[PIXL_NUM][PIXL_NUM];
};


#endif /* backgroundLayer_hpp */
