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

#endif /* Header_h */
