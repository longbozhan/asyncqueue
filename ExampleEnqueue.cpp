

int main()
{
    Manager mgr;
    int cmdCount = 1;
    if (false == mgr.init(cmdCount))
    {
        printf("mgr init fail\n");
        exit(-1);
    }

    const char * sCmd = "This is a job";
    int ret = mgr.addToQueue(0, (const void *) sCmd, strlen(sCmd));
    if (ret != 0)
    {
        printf("add to queue fail\n");
    }

    return ret;
}
