//
//  Header.h
//  HunterAndSnake
//
//  Created by zeyong shan on 7/7/17.
//
//

#ifndef Header_h
#define Header_h


//Screen adapter defination
#define GET_ORI_VIS auto origin = Director::getInstance()->getVisibleOrigin();\
auto visiableSize = Director::getInstance()->getVisibleSize()
#define SCREEN_CENTER origin.x + visiableSize.width/2, origin.y + visiableSize.height/2


//The definations for Layer childern
#define BACKGROUND_LAYER            0
#define HUNTER_LAYER                1


//The definations for sceneTypes
#define HUNTER_SCENE_TYPE    0
#define SNAKE_SCENE_TYPE     1

//data types from the server
#define DATA_TYPE_NUM 3
#define APPLY_POS_RESULT_TYPE   0
#define UPDATE_POS_RESULT_TYPE  1
#define ROOM_INFO_TYPE          2

//role info
#define MAX_NUM_SHIP            6



//function defination
void logPosition(cocos2d::Point p);
void logDirection(cocos2d::Vec2 v);
void split(std::string*&, std::string, int&);


#endif /* Header_h */
