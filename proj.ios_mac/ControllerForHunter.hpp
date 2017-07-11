//
//  ControllerForHunter.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/10/17.
//
//

#ifndef ControllerForHunter_hpp
#define ControllerForHunter_hpp
#include "ControllerLayer.hpp"

class ControllerForHunter: public ControllerLayer
{
public:
    CREATE_FUNC(ControllerForHunter);
    virtual bool init();
private:
    void initScheduler();
    
};


#endif /* ControllerForHunter_hpp */
