

Queue::Queue(int cmd)
{
    mName = "./tmp/";
    mName += cmd;

    mCmd = cmd;
    store.init(mName, cmd);
    openFifo();
}

void Queue::add(const Job & job)
{
    store.write(job);
    notify();
}

bool Queue::get(Job & job, int timeout)
{
    while(true)
    {
        if (store.read(job))
        {
            return true;
        }
        else if (timeount == 0)
        {
            break;
        }
        else if (wait(timeout) && store.read(job))
        {
            return true;
        }
        else if (timeout > 0)
        {
            break;
        }
    }

    return false;
}

void Queue::openFifo()
{
    string fifoName = ".fifo";
    if (::mkfifo(fifoName.c_str(), 0755) < 0 && (errno != EEXIST))
    {
        printf("filename:%s err:%s\n", fifoName.c_str(), strerror(errno))
    }

    mFifo = ::open(fifoName.c_str(), O_RDWR | O_NONBLOCK);
    if (mFifo == -1)
    {
        printf("open %s error: %s", fifoName.c_str(), strerror(errno));
    }
}

void Queue::notify()
{
    write(mFifo, '1', 1);
}

bool wait(int timeout)
{
    int rc = ::select(_fifo + 1, &fs, 0, 0, (timeout >= 0 ? &tv : 0));
    if (rc > 0)
    {
        char c[64];
        int ret = ::read(mFifo, c, sizeof(c));
        if (ret <= 0 && errno != EAGAIN)
            return true;
    }
    return false;
}

