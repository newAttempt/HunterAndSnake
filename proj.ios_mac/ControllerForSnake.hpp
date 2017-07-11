//
//  ControllerForSnake.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/10/17.
//
//

#ifndef ControllerForSnake_hpp
#define ControllerForSnake_hpp

#include "ControllerLayer.hpp"

class ControllerForSnake: public ControllerLayer
{
public:
    CREATE_FUNC(ControllerForSnake);
    virtual bool init();
private:
    void initScheduler();
};

#endif /* ControllerForSnake_hpp */
