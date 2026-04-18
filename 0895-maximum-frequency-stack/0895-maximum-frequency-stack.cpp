class FreqStack {
public:
    unordered_map<int,int>mp;
    unordered_map<int,stack<int>>st;
    int mx;
    FreqStack() {
        mx=0;
    }
    
    void push(int val) {
        mp[val]++;
        int freq=mp[val];
        mx=max(mx,freq);
        st[freq].push(val);
    }
    
    int pop() {
        int ans=st[mx].top();
        st[mx].pop();

        mp[ans]--;
        if(st[mx].empty())
        {
            mx--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */