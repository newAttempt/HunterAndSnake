//
//  Client.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/20/17.
//
//

#ifndef Client_hpp
#define Client_hpp
#include "ODSocket.h"

class Client: cocos2d::Node
{
public:
    CREATE_FUNC(Client);
    virtual bool init();
    
private:
    void receiveData();
    ODSocket socket;
};
#endif /* Client_hpp */
