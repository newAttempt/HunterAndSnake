//
//  Client.cpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/20/17.
//
//

#include "Client.hpp"



bool Client::init()
{
    if(!Node::init())
        return false;
    socket.Init();
    socket.Create(AF_INET, SOCK_STREAM);
    const char* ip = "10.0.0.44";
    int   port     = 5000;
    bool  result   = socket.Connect(ip, port);
    
    if (result) {
        CCLOG("connect to server success!");
        
        // 开启新线程，在子线程中，接收数据
        socket.Send("0", 1);
        socket.Connect(ip, port);
        std::thread recvThread = std::thread(&Client::receiveData, this);
        recvThread.detach(); // 从主线程分离
    }
    else {
        CCLOG("can not connect to server");
        return false;
    }
    return true;
}


void Client::receiveData()
{
    // 因为是强联网
    // 所以可以一直检测服务端是否有数据传来
    while (true) {
        
        // 接收数据 Recv
        
        char data[512] = "";
        int result = socket.Recv(data, 512, 0);
        cocos2d::log("result is : sdfasdfsfsdf%d", result);
        
        
        // 与服务器的连接断开了
        if (result <= 0) break;
        
       CCLOG("%s\n\n\n\n\n\n\n\n\n\n\\n\n\n\n\n\n", data);
    }
    // 关闭连接
    socket.Close();
}
