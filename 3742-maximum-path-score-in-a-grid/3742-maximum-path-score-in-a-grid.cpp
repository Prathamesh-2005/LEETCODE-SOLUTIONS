class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,int k,vector<vector<vector<int>>>& dp)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m || k<0)
        {
            return INT_MIN;
        }

        int right=INT_MIN;
        int down=INT_MIN;
        int curr=k;
        if(grid[i][j]==0)
        {
            curr-=0;
        }
        else{
            curr-=1;
        }
        if(curr<0)
        {
            return INT_MIN;
        }
        if(i==n-1 && j==m-1)
        {
            return grid[i][j];
        }

        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        right=solve(i+1,j,grid,curr,dp);

        down=solve(i,j+1,grid,curr,dp);
        int ans=INT_MIN;

        if(right!=INT_MIN)
        {
            ans=max(ans,right+grid[i][j]);
        }
        if(down!=INT_MIN)
        {
            ans=max(ans,down+grid[i][j]);
        }
        return dp[i][j][k]=ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=solve(0,0,grid,k,dp);
        return (ans==INT_MIN ? -1 : ans);
    }
};