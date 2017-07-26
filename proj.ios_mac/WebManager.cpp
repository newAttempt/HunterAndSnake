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
    this -> idHandler        = idHandler;
    this -> startGameHandler = startHandler;
    std::thread idThread = std::thread(&WebManager::checkID, this);
    std::thread startThread = std::thread(&WebManager::checkStart, this);
    idThread.detach();
    startThread.detach();
}


void WebManager::checkID()
{
    while (true) {
        string temp = DataBufferPool::dequeue(0);
        if(temp.empty())
            continue;
        if(temp == "s")
        {
            DataBufferPool::pushBack(temp, 0);
            continue;
        }
        idHandler(temp);
        Director::getInstance()->getScheduler()->unschedule("check_id", this);
        break;
    }
}


void WebManager::checkStart()
{
    while (true) {
        string temp = DataBufferPool::dequeue(0);
        if(temp.empty())
            continue;
        if(temp != "s")
        {
            DataBufferPool::pushBack(temp, 0);
            continue;
        }
        startGameHandler();
        break;
    }
}


