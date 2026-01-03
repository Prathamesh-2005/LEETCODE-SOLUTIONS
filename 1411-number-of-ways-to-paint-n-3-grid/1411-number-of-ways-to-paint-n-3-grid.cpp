class Solution {
public:
        vector<string>column;
    int mod=1e9+7;
    void generate(string curr,char prev,int m,int l)
    {
        if(l==m)
        {
            column.push_back(curr);
            return ;
        }
        for(auto& ch:{'R','G','B'})
        {
            if(ch==prev)
            {
                continue;
            }
            generate(curr+ch,ch,m,l+1);
        }
    }
    int solve(int remain,int idx,int m,vector<vector<int>>& dp)
    {
        if(remain==0)
        {
            return 1;
        }
        int ways=0;
        string prev=column[idx];
        if(dp[remain][idx]!=-1)
        {
            return dp[remain][idx];
        }
        for(int i=0;i<column.size();i++)
        {
            if(i==idx)
            {
                continue;
            }
            string curr=column[i];
            bool flag=true;
            for(int j=0;j<m;j++)
            {
                if(prev[j]==curr[j])
                {
                    flag=false;
                    break;
                }
            }

            if(flag)
            {
                ways=(ways+solve(remain-1,i,m,dp))%mod;
            }
        }
        return dp[remain][idx]=ways;
    }
    int numOfWays(int n) {
        int mod=1e9+7;
        int m=3;
        generate("",'@',m,0);

        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(column.size(),-1));
        for(int i=0;i<column.size();i++)
        {
            ans = (ans + solve(n-1, i, m, dp)) % mod;
        }
        return ans;
    }
};