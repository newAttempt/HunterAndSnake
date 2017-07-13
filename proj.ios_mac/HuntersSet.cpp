//
//  HuntersMap.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/12/17.
//
//

#include "HuntersSet.hpp"
USING_NS_CC;
using namespace std;

HunterSet::HunterSet()
{
    hunterMap.clear();
}


bool HunterSet::addHunter(string uniqueID, Point hunterPosition)
{
    auto search = hunterMap.find(uniqueID);
    if(search != hunterMap.end())
        return false;
    hunterMap[uniqueID] = hunterPosition;
    return true;
}


HunterSet::~HunterSet()
{
    hunterMap.clear();
}
