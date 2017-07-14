//
//  HuntersMap.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/12/17.
//
//

#include "HuntersSet.hpp"
#include "Defines.h"
USING_NS_CC;
using namespace std;

bool HunterSet::init()
{
    if(!Node::init())
        return false;
    
    return true;
}

HunterSet::HunterSet()
{
    hunterMap.clear();
}


bool HunterSet::addHunter(string uniqueID, HunterStatus* status)
{
    auto search = hunterMap.find(uniqueID);
    if(search != hunterMap.end())
        return false;
    hunterMap[uniqueID] = status;
    return true;
}

void HunterSet::print(string s)
{
    for(auto it = hunterMap.begin(); it!=hunterMap.end(); ++it)
    {
        logPosition(it -> second -> getPosition());
        logDirection(it -> second -> getDirection());
    }
}

HunterSet::~HunterSet()
{
    hunterMap.clear();
}
