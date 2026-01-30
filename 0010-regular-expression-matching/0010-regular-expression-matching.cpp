class Solution {
public:
    int dp[21][21];
    bool solve(string s,string p,int i,int j)
    {
        if(j==p.length())
        {
            if(i==s.length())
            {
                return true;
            }
            return false;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        bool first=(i!=s.length() && j!=p.length() && (p[j]==s[i] || p[j]=='.'));
        if(p[j+1]=='*')
        {
            bool not_take=solve(s,p,i,j+2);
            bool take=(first && solve(s,p,i+1,j));
            return dp[i][j]=(take || not_take);
        }else{
            return dp[i][j]=(first && solve(s,p,i+1,j+1));
        }
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s,p,0,0);
    }
};