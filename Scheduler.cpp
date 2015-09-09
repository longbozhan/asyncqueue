/**
* @author zhanlongbo@baidu.com
* @date 2015/09/07 19:12
* @brief
*
***/

#include "Scheduler.h"

Scheduler::Scheduler()
{

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
    

    

}
