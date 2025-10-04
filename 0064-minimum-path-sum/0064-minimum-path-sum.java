class Solution {
    public int SODAV(int i,int j,int [][]grid,int [][]dp)
    {
        if(i==0 && j==0)
        {
            return grid[0][0];
        }
        if(i<0 || j<0)
        {
            return Integer.MAX_VALUE;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=0,left=0;
        up=SODAV(i-1,j,grid,dp);
        left=SODAV(i,j-1,grid,dp);
        return dp[i][j]=grid[i][j]+Math.min(up,left);
    }
    public int minPathSum(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int [][]dp=new int[n][m];

        for(int i=0;i<n;i++)
        {
            Arrays.fill(dp[i],-1);
        }
        return SODAV(n-1,m-1,grid,dp);
    }
}