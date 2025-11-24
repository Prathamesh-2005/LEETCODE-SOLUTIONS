class Solution {
public:
    bool check(string& s)
    {
        long long num=0;
        for(int i=0;i<s.length();i++)
        {
            int bit=s[i]-'0';
            num=(num*2+bit)%5;
        }

        return (num==0);
    }
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>ans(n,false);
        string str="";
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            str+=(num+'0');
            ans[i]=check(str);
        }
        return ans;
    }
};