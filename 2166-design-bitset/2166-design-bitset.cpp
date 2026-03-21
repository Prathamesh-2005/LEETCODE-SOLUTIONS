class Bitset {
public:
    string bits;
    int n;
    int cnt;
    int flag;
    Bitset(int size) {
        bits.resize(size,'0');
        n=size;
        cnt=0;
        flag=false;
    }
    char help(int idx){
        if(flag==false)
        {
            return bits[idx];
        }
        return (bits[idx]=='0' ? '1' : '0');
    }
    void fix(int idx) {
        if(help(idx)=='0')
        {
            if(!flag)
            {
                bits[idx]='1';
            }else{
                bits[idx]='0';
            }
            cnt++;
        }
    }
    
    void unfix(int idx) {
        if(help(idx)=='1')
        {
            if(!flag)
            {
                bits[idx]='0';
            }else{
                bits[idx]='1';
            }
            cnt--;
        }
    }
    
    void flip() {
       flag=!flag;
       cnt=n-cnt;
    }
    
    bool all() {
        return cnt==n;
    }
    
    bool one() {
        return cnt>=1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string ans=bits;
        if(flag)
        {
            for(char& c:ans)
            {
                c=(c=='0') ? '1' : '0';
            }
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */