class Solution {
public:
    int n;
    int dp[301];
    bool solve(int idx ,string& s,set<string>& st)
    {
        if(idx==n)
        {
            return true;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        if(st.find(s)!=st.end())
        {
            return true;
        }

        for(int l=1;l<=n;l++)
        {
            string temp=s.substr(idx,l);

            if(st.find(temp)!=st.end() && solve(idx+l,s,st))
            {
                return dp[idx]=true;
            }
        }

        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        memset(dp,-1,sizeof(dp));
        set<string>st(wordDict.begin(),wordDict.end());

        return solve(0,s,st);
    }
};