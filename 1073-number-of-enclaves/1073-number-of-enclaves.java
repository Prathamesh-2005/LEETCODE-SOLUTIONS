class Solution {
    int [][] direc={{1,0},{0,1},{-1,0},{0,-1}};
    public boolean safe(int i,int j,int n,int m)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    public void dfs(int i,int j,boolean [][]vis,int [][]grid)
    {
        int n=grid.length;
        int m=grid[0].length;
        vis[i][j]=true;
        
        for(int []d:direc)
        {
            int I=i+d[0];
            int J=j+d[1];

            if(safe(I,J,n,m) && grid[I][J]==1 && !vis[I][J])
            {
                dfs(I,J,vis,grid);
            }
        }
    }
    public int numEnclaves(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        boolean [][] vis=new boolean [n][m];

        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j]==1)
            {
                dfs(0,j,vis,grid);
            }

            if(!vis[n-1][j] && grid[n-1][j]==1)
            {
                dfs(n-1,j,vis,grid);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
            {
                dfs(i,0,vis,grid);
            }

            if(!vis[i][m-1] && grid[i][m-1]==1)
            {
                dfs(i,m-1,vis,grid);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
}