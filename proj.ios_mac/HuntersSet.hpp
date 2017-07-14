//
//  HuntersMap.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/12/17.
//
//

#ifndef HuntersSet_hpp
#define HuntersSet_hpp
#include "HunterStatus.hpp"

class HunterSet: cocos2d::Node
{
public:
    CREATE_FUNC(HunterSet);
    virtual bool init();
    HunterSet();
    ~HunterSet();
    bool addHunter(std::string uniqueID, HunterStatus *);
    void print(std::string);
private:
    std::map<std::string, HunterStatus *> hunterMap;
};

#endif /* HuntersMap_hpp */
