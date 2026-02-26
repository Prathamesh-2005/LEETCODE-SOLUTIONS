class MyCircularQueue {
public:
    vector<int>q;
    int f,r;
    int sz;
    int curr;
    MyCircularQueue(int k) {
        f=0;
        r=-1;
        q.resize(k,-1);
        sz=k;
        curr=0;
    }
    
    bool enQueue(int value) {
        if(isFull())
        {
            return false;
        }
        r=(r+1)%sz;
        q[r]=value;
        curr++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        {
            return false;
        }
        f=(f+1)%sz;
        curr--;
        return true;
    }
    
    int Front() {
        if(curr==0)
        {
            return -1;
        }
        return q[f];
    }
    
    int Rear() {
        if(curr==0)
        {
            return -1;
        }
        return q[r];
    }
    
    bool isEmpty() {
        return (curr==0);
    }
    
    bool isFull() {
        return (curr==sz);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */