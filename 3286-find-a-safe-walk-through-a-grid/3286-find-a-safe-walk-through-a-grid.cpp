class Solution {
public:
    vector<vector<int>> direc = {{1,0},{0,1},{-1,0},{0,-1}};

    bool safe(int i,int j,int n,int m)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }

    bool solve(int i,int j,vector<vector<int>>& grid,int health,
               int n,int m,vector<vector<int>>& vec)
    {
        if(!safe(i,j,n,m))
            return false;

        health -= grid[i][j];

        if(health < 1)
            return false;

        if(i==n-1 && j==m-1)
            return true;

        if(vec[i][j] >= health)
            return false;

        vec[i][j] = health;

        for(auto &d : direc)
        {
            int ni = i + d[0];
            int nj = j + d[1];

            if(solve(ni,nj,grid,health,n,m,vec))
                return true;
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vec(n, vector<int>(m, -1));

        return solve(0,0,grid,health,n,m,vec);
    }
};