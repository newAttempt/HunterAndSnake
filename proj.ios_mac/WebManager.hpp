//
//  WebManager.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/25/17.
//
//

#ifndef WebManager_hpp
#define WebManager_hpp

class WebManager: public cocos2d::Node
{
public:
    CREATE_FUNC(WebManager);
    virtual bool init();
    void signUpPosition(std::function<void (std::string)> idHandler, std::function<void ()> startGameHandler);
private:
    void checkID();
    void checkStart();
    std::function<void (std::string)> idHandler;
    std::function<void ()> startGameHandler;
};

#endif /* WebManager_hpp */
