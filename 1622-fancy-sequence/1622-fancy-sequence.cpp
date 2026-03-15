class Fancy {
public:
    typedef long long ll;
    vector<ll>seq;
    ll m=1e9+7;
    ll add;
    ll mul;
    Fancy() {
        add=0;
        mul=1;
    }
    ll power(ll a,ll b)
    {
        if(b==0)
        {
            return 1;
        }
        ll half=(power(a,b/2));
        ll res=(half*half)%m;
        if(b & 1)
        {
            res=(res*a)%m;
        }
        return res;
    }
    void append(int val) {
        //need to learn FLT :) .....
        ll x=((val-add+m)% m* power(mul,m-2))%m; 
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add=(add+inc)%m;
    }
    
    void multAll(int multi) {
        add=(add*multi)%m;
        mul=(mul*multi)%m;
    }
    
    int getIndex(int idx) {
        if(seq.size()<=idx)
        {
            return -1;
        }
        ll x=seq[idx];
        return ((x*mul)+add)% m;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */