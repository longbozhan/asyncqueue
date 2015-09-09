

Store::Store()
{

}

Store::~Store()
{

}

bool Store::init(const string & queueName, int cmd)
{
    readFd = open(queueName + ".r");
    writeFd = open(queueName + ".w");

    readLockFile = queueName + ".rlock";
    writeLockFile = queueName + ".wlock";

}


int Store::write(const Job & job)
{

    Lock lock(writeLockFile);

    Position pos;
    getNextWrite(pos);

    Header head;
    head.len = job.getLen();
    
    writeHeader(head);
    writeBody(job);

    return 0;
}

int Store::read(Job & job)
{
    Lock lock(readLockFile);

    Position pos;
    getNextRead(pos);

    Header head;
    readHeader(head);
    readBody(head, job);

    return 0;
}

int Store::open(const string fileName)
{

}

int Store::readHeader(Header & head)
{

}

int Store::writeHeader(const Header & head)
{

}

int Store::readBody(const Header & head, Job & job)
{

}

int Store::writeBody(const Job & job)
{

}
