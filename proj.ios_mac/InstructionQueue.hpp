//
//  InstructionQueue.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/22/17.
//
//

#ifndef InstructionQueue_hpp
#define InstructionQueue_hpp

class InstructionQueue
{
public:
    static void init();
    static void enqueue(std::string);
    static std::string dequeue();
private:
    static std::mutex mutex;
    static std::queue<std::string> queue;
    static int size;
};


#endif /* InstructionQueue_hpp */
