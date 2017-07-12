//
//  HuntersMap.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/12/17.
//
//

#ifndef HuntersSet_hpp
#define HuntersSet_hpp

class HunterSet
{
public:
    HunterSet();
    ~HunterSet();
    bool addHunter(std::string uniqueID, cocos2d::Point hunterPosition);
private:
    std::map<std::string, cocos2d::Point> hunterMap;
};

#endif /* HuntersMap_hpp */
