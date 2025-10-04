class Solution {
    public int solve(int i,int j,int [][]obstacleGrid,int [][]dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(i==0 && j==0)
        {
            return 1;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int up=solve(i-1,j,obstacleGrid,dp);
        int left=solve(i,j-1,obstacleGrid,dp);

        return dp[i][j]=up+left;
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n=obstacleGrid.length;
        int m=obstacleGrid[0].length;
        int [][]dp=new int[n][m];
        
        if(obstacleGrid[0][0]==1 && n==1 && m==1)
        {
            return 0;
        }
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0)
                {
                    continue;
                }
                int  up = 0, left = 0;
                if (i > 0) up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[n-1][m-1];
    }
}