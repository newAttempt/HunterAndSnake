//
//  DataBufferPool.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/22/17.
//
//

#include "DataBufferPool.hpp"
USING_NS_CC;
using namespace std;

mutex           DataBufferPool::mutex[DATA_TYPE_NUM];
queue<string>   DataBufferPool::queue[DATA_TYPE_NUM];
int             DataBufferPool::size[DATA_TYPE_NUM];

void DataBufferPool::init()
{
    for(int i = 0; i<DATA_TYPE_NUM; ++i)
        size[i] = 0;
}


void DataBufferPool::enqueue(string data)
{
    char i = data[0];
    int index = i - '0';
    if(index >= DATA_TYPE_NUM || index < 0)
        return;
    mutex[index].lock();
    data.erase(0, 2);
    queue[index].push(data);
    ++size[index];
    mutex[index].unlock();
}

string DataBufferPool::dequeue(int data_type)
{
    string result;
    mutex[data_type].lock();
    if(size[data_type] > 0)
    {
        result = queue[data_type].front();
        queue[data_type].pop();
        --size[data_type];
    }else {
        result.clear();
    }
    mutex[data_type].unlock();
    return result;
}
