//
//  DataBufferPool.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/22/17.
//
//

#ifndef DataBufferPool_hpp
#define DataBufferPool_hpp
#include "Defines.h"

class DataBufferPool
{
public:
    static void init();
    static void enqueue(std::string);
    static void pushBack(std::string, int);
    static std::string dequeue(int);
private:
    static std::mutex mutex[DATA_TYPE_NUM];
    static std::queue<std::string> queue[DATA_TYPE_NUM];
    static int size[DATA_TYPE_NUM];
};

#endif /* DataBufferPool_hpp */
