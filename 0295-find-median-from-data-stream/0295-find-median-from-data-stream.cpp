class MedianFinder {
public:
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty() || num<=mx.top())
        {
            mx.push(num);
        }else{
            mn.push(num);
        }

        if(abs((int)mx.size()-(int)mn.size())>1)
        {
            int nums=mx.top();
            mx.pop();
            mn.push(nums);
        }else if(mx.size()<mn.size()){
            int nums=mn.top();
            mn.pop();
            mx.push(nums);
        }
    }
    
    double findMedian() {
        int n=mx.size();
        int m=mn.size();

        if((m+n)&1)
        {
            return mx.top();
        }else{
            return (mx.top() + mn.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */