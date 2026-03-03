class Solution {
public:
    string invert(string& str)
    {
        string ans="";
        for(auto& c:str)
        {
            if(c=='0')
            {
                ans+="1";
            }else{
                ans+="0";
            }
        }
        return ans;
    }
    string solve(int curr,int n,int k,string ans)
    {
        if(curr==n)
        {
            return ans;
        }
        string str=invert(ans);
        reverse(str.begin(),str.end());
        ans= ans + "1" + str;
        return solve(curr+1,n,k,ans);
    }
    char findKthBit(int n, int k) {
        return solve(1,n,k,"0");
    }
};