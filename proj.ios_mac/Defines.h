//
//  Header.h
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#ifndef Header_h
#define Header_h

#define GET_ORI_VIS auto origin = Director::getInstance()->getVisibleOrigin();\
auto visiableSize = Director::getInstance()->getVisibleSize()

#define SCREEN_CENTER origin.x + visiableSize.width/2, origin.y + visiableSize.height/2


//The definations for Layer childern
#define BACKGROUND_LAYER            0
#define HUNTER_LAYER                1




//The definations for sceneTypes
#define HUNTER_SCENE_TYPE    0
#define SNAKE_SCENE_TYPE     1
#endif /* Header_h */
void logPosition(cocos2d::Point p);
void logDirection(cocos2d::Vec2 v);

#define MAX_NUM_SHIP 6
