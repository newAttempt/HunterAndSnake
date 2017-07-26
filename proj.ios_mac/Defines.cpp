//
//  Defines.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/13/17.
//
//

#include <stdio.h>


void logPosition(cocos2d::Point p)
{
    cocos2d::log("pos:(%f, %f)", p.x, p.y);
}


void logDirection(cocos2d::Vec2 v)
{
    cocos2d::log("dir:(%f, %f)", v.x, v.y);
}


void split(std::string* &arr, std::string str, int &max, char splitC)
{
    max = 0;
    for(int i = 0; i<str.length(); ++i)
    {
        if(str[i] == splitC)
            ++max;
    }
    arr = new std::string[max];
    for(int i=0, j=0; i<str.length(); ++i)
    {
        if(str[i] == splitC)
        {
            ++j;
            continue;
        }
        arr[j]+= str[i];
    }
}
