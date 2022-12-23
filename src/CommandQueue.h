#ifndef __COMMAND_QUEUE_H__
#define __COMMAND_QUEUE_H__

#include "Command.h"

#include <queue>


class CommandQueue
{
public:
    void push(const Command& command);
    Command pop();
    bool isEmpty() const;


private:
    std::queue<Command> mQueue;
};

#endif // __COMMAND_QUEUE_H__
