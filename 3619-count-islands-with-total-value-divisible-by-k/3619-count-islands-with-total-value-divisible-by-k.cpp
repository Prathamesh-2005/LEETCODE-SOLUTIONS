class Solution {
public:
    vector<vector<int>>direc={{1,0},{0,1},{-1,0},{0,-1}};
    bool safe(int i,int j,int n,int m)
    {
        return (i<n && i>=0 && j<m && j>=0);
    }
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited,int& sum,int n,int m)
    {
        if(!safe(i,j,n,m))
        {
            return ;
        }
        if(grid[i][j]==0 || visited[i][j])
        {
            return ;
        }
        visited[i][j]=true;
        sum+=grid[i][j];

        for(auto& vec:direc)
        {
            int I=i+vec[0];
            int J=j+vec[1];
            dfs(grid,I,J,visited,sum,n,m);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && !visited[i][j])
                {
                    int sum=0;
                    dfs(grid,i,j,visited,sum,n,m);
                    if(sum%k==0)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};