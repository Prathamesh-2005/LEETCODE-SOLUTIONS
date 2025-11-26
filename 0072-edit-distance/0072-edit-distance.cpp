class Solution {
public:
    int solve(int i,int j,string word1,string word2,int m,int n,vector<vector<int>>& dp)
    {
        if(j==n)
        {
            return m-i;
        }
        else if(i==m)
        {
            return n-j;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(word1[i]==word2[j])
        {
            return dp[i][j]=solve(i+1,j+1,word1,word2,m,n,dp);
        }
        int insert=1+solve(i,j+1,word1,word2,m,n,dp);
        int dele=1+solve(i+1,j,word1,word2,m,n,dp);
        int replace=1+solve(i+1,j+1,word1,word2,m,n,dp);

        return dp[i][j]=min({insert,dele,replace});
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,word1,word2,m,n,dp);
    }
};