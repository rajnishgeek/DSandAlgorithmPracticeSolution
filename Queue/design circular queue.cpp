class MyCircularQueue {
    int *queue;
    int frontindex = 0;
    int rearindex = -1;
    int size = 0;
    int queueSize;
public:
    MyCircularQueue(int k)
    {
        queue = new int[k];
        queueSize = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        rearindex = (rearindex + 1) % queueSize;
        queue[rearindex] = value;
        size++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        frontindex = (frontindex + 1) % queueSize;
        size--;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return queue[frontindex];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return queue[rearindex];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull() {
        return size == queueSize;
    }
};

//*********************************************************************************
class MyCircularQueue {
    int *queue;
    int frontindex;
    int rearindex;
    int size;
public:
    MyCircularQueue(int k)
    {
        size = k;
        queue = new int[k];
        frontindex = rearindex = -1;
    }

    bool enQueue(int value)
    {
        if ((frontindex == 0 && rearindex == size - 1) || (rearindex == (frontindex - 1) % (size - 1)))
            return false;
        else if (frontindex == -1)
        {
            frontindex = rearindex = 0;
            queue[rearindex] = value;
        }
        else if (rearindex == size - 1 && front != 0)
        {
            rearindex = 0;
            queue[rearindex] = value;
        }
        else
        {
            rearindex++;
            queue[rearindex] = value;
        }
        return true;
    }

    bool deQueue()
    {
        if (frontindex == -1)
            return false;
        else if (frontindex == rearindex)
            frontindex = rearindex = -1;
        else if (frontindex == size - 1)
            frontindex = 0;
        else
            frontindex++;
        return true;
    }

    int Front()
    {
        if (frontindex == -1)
            return -1;
        return queue[frontindex];
    }

    int Rear()
    {
        if (rearindex == -1)
            return -1;
        return queue[rearindex];
    }

    bool isEmpty()
    {
        return frontindex == -1;
    }

    bool isFull() {
        return (frontindex == 0 && rearindex == size - 1) || (rearindex == (frontindex - 1) % (size - 1));
    }
};