//
//  InstructionQueue.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/22/17.
//
//

#include "InstructionQueue.hpp"
USING_NS_CC;
using namespace std;

mutex           InstructionQueue::mutex;
queue<string>   InstructionQueue::queue;
int             InstructionQueue::size;

void InstructionQueue::init()
{
    size = 0;
}


void InstructionQueue::enqueue(string instruction)
{
    mutex.lock();
    queue.push(instruction);
    ++size;
    mutex.unlock();
}

string InstructionQueue::dequeue()
{
    string result;
    mutex.lock();
    if(size != 0)
    {
        result = queue.front();
        queue.pop();
        size = size - 1;
    }else {
        result.clear();
    }
    mutex.unlock();
    return result;
}

