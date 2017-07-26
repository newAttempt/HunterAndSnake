//
//  WebManager.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/25/17.
//
//

#include "WebManager.hpp"
#include "InstructionQueue.hpp"
#include "DataBufferPool.hpp"
using namespace std;
USING_NS_CC;

bool WebManager::init()
{
    if(!Node::init())
        return false;
    
    return true;
}


void WebManager::signUpPosition(function <void (string)> idHandler, function<void ()> startHandler)
{
    InstructionQueue::enqueue("0");
    Director::getInstance()->getScheduler()->schedule([idHandler, this](float){
        string temp = DataBufferPool::dequeue(0);
        if(temp.empty())
            return;
        if(temp == "s")
        {
            DataBufferPool::enqueue("s");
            return;
        }
        idHandler(temp);
        Director::getInstance()->getScheduler()->unschedule("check_id", this);
    }, this, 0.01, kRepeatForever, 0, true, "check_id");
    
    Director::getInstance()->getScheduler()->schedule([startHandler, this](float){
        string temp = DataBufferPool::dequeue(0);
        if(temp.empty())
            return;
        if(temp != "s")
        {
            DataBufferPool::enqueue(temp);
            return;
        }
        startHandler;
        Director::getInstance()->getScheduler()->unschedule("check_start_game", this);
    }, this, 0.01, kRepeatForever, 0, true, "check_start_game");
}
