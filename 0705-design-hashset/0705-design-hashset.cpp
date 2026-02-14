class MyHashSet {
public:
   vector<int>st;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(contains(key))
        {
            return ;
        }
        auto it=lower_bound(st.begin(),st.end(),key);
        st.insert(it,key);
    }
    int b_search(vector<int>& vec,int target)
    {
        int n=vec.size();
        int l=0,h=n-1;

        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(vec[mid]==target)
            {
                return mid;
            }else if(vec[mid]<target)
            {
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return -1;
    }
    void remove(int key) {
        int idx=b_search(st,key);
        if(idx==-1)
        {
            return ;
        }
        st.erase(st.begin()+idx);
        return ;
    }
    
    bool contains(int key) {
        if(b_search(st,key)==-1)
        {
            return false;
        }else{
            return true;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */