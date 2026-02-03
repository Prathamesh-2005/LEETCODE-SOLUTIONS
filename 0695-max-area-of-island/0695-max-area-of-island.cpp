class Solution {
public:
    vector<vector<int>>direc={{-1,0},{1,0},{0,1},{0,-1}};
    bool safe(int i,int j,int n,int m){
        return (i<0 || j<0 || i>=n || j>=m);
    }
    void dfs(vector<vector<int>>& grid,int&  curr,int i,int j,int n,int m,vector<vector<bool>>& check)
    {
        if(safe(i,j,n,m))
        {
            return ;
        }
        if(grid[i][j]==0 || check[i][j]==true)
        {
            return ;
        }
        curr++;
        check[i][j]=true;
        for(auto& dir:direc)
        {
            int I=i+dir[0];
            int J=j+dir[1];
            dfs(grid,curr,I,J,n,m,check);
        }
        return ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>>check(n,vector<bool>(m,false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1 && !check[i][j])
                {
                    int curr=0;
                    dfs(grid,curr,i,j,n,m,check);
                    ans=max(curr,ans);
                }
            }
        }

        return ans;
    }
};