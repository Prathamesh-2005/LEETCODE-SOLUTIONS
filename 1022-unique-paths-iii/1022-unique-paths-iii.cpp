class Solution {
public:
    vector<vector<int>>dire={{1,0},{0,1},{-1,0},{0,-1}};
    int non_obst=0;
    int n,m;
    void solve(vector<vector<int>>& grid,int i,int j,int obst,int& ans)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==-1)
        {
            return ;
        }

        if(grid[i][j]==2)
        {
            if(obst==non_obst)
            {
                ans++;
            }
            return ;
        }

        grid[i][j]=-1;

        for(auto& v:dire)
        {
            int i_=i+v[0];
            int j_=j+v[1];

            solve(grid,i_,j_,obst+1,ans);
        }
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        int i_s=0;
        int j_s=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 || grid[i][j]==1)
                {
                    non_obst++;
                }

                if(grid[i][j]==1)
                {
                    i_s=i;
                    j_s=j;
                }
            }
        }

        solve(grid,i_s,j_s,0,ans);
        return ans;
    }
};