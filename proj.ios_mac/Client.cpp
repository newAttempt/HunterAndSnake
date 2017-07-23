//
//  Client.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/20/17.
//
//

#include "Client.hpp"
#include "InstructionQueue.hpp"
#include "DataBufferPool.hpp"
USING_NS_CC;
using namespace std;


bool Client::init()
{
    if(!Node::init())
        return false;
    
    socket.Init();
    InstructionQueue::init();
    DataBufferPool::init();
    socket.Create(AF_INET, SOCK_STREAM);
    const char* ip   = "10.0.0.44";
    int   port       = 5000;
    connectionStatus = false;
    
    bool  result   = socket.Connect(ip, port);
    if (result) {
        connectionStatus = true;
        CCLOG("connect to server success!");
        socket.Connect(ip, port);
        std::thread recvThread = std::thread(&Client::receiveData, this);
        std::thread sendThread = std::thread(&Client::sendData,    this);
        recvThread.detach();
        sendThread.detach();
    }
    else {
        CCLOG("can not connect to server");
        return false;
    }
    
    return true;
}


void Client::receiveData()
{
    while (true) {
        char data[512] = "";
        int result = socket.Recv(data, 512, 0);
        if (result <= 0) {
            log("connection closed!");
            //connectionStatus = false;
            //break;
        }
        string data_str(data);
        DataBufferPool::enqueue(data_str);
    }
    socket.Close();
}


void Client::sendData()
{
    ///*
    for(int i=0; i<20; ++i)
    {
        InstructionQueue::enqueue("0");
    }
     //*/
    InstructionQueue::enqueue("2 0-14");
    while (connectionStatus) {
        string instruction = InstructionQueue::dequeue();
        if(!instruction.empty())
        {
            instruction += "x";
            socket.Send(instruction.c_str(), instruction.length());
        }
        
    }
}


