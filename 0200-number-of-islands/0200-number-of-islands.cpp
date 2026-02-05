class Solution {
public:
    vector<vector<int>>direc={{-1,0},{0,-1},{1,0},{0,1}};
    bool safe(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m,vector<vector<bool>>& check)
    {
        if(!safe(i,j,n,m))
        {
            return ;
        }
        if(grid[i][j]=='0' || check[i][j])
        {
            return ;
        }
        check[i][j]=true;

        for(auto& dir:direc)
        {
            int I=i+dir[0];
            int J=j+dir[1];

            dfs(grid,I,J,n,m,check);
        }

        return ;

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> check(n, vector<bool>(m,false));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]=='1' && check[i][j]==false)
                {
                    dfs(grid,i,j,n,m,check);
                    ans++;
                }
            }
        }
        return ans;
    }
};