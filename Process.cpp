
Process::Process(int cmd)
{
    mCmd = cmd;
}

int Process::start()
{
    int pid = fork();
    if (pid == 0)
    {
        process();
    }
    else if (pid > 0)
    {
        mPid = pid;
    }
    else
    {
        printf("error\n");
    }
}

int Process:process()
{
    queue = new Queue(mCmd);

    while(true)
    {
        Job job;
        while(!queue->get(job, 1000));

        handler(job);
    }

    return 0;
}


