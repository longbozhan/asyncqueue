/**
* @author zhanlongbo@baidu.com
* @date 2015/09/07 19:12
* @brief
*
***/

#include "Scheduler.h"

Scheduler::Scheduler(int cmdCount)
{
    mCmdCount = cmdCount;
}

Scheduler::~Scheduler()
{

}

int Scheduler::init()
{

}

int Scheduler::run()
{
    Utils::runAsDeamon();
    Utils::signal();
    
    for(int i = 0; i < mCmdCount; i++)
    {
        Process * p = new Process(i);

        vecProcess.push(p);
        p.start();
    }

    while(true)
    {
        int status = 0;
        pid_t pid = waitpid(-1, &status, 0);
        if (pid == -1)
        {
            printf("error waitpid\n");
            continue;
        }
        for(int i = 0; i < vecProcess.size(); i++)
            if (pid == vecProcess[i]->getPid())
            {
                vecProcess[i].start();
            }
    }
}
