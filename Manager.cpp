
bool Manager::init(int cmdCount)
{
    for(int i = 0; i < cmdCount; i++)
    {
        Queue * q = new Queue(i);

        if (q == NULL)
        {
            printf("init queue(%d) fail\n", i);
            return false;
        }
        mapQueue[i] = q;
    }
    return true;
}

int Manager::addToQueue(int cmd, const void * content, size_t size)
{
    Job job;
    job.setCmd(cmd);
    job.setContent(content, size);

    mapQueue[cmd].add(job);

    return 0;
}
