class Solution {
public:
    bool check(int n)
    {
        string str=to_string(n);
        for(auto& c:str)
        {
            if(c=='0')
            {
                return true;
            }
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            int a=i;
            int b=n-i;
            if(a+b==n && !check(a) && !check(b))
            {
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }
        }
        return ans;
    }
};