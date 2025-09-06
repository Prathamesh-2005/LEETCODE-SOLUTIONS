class Solution {
public:
    vector<vector<int>>direc={{1,0},{0,1},{-1,0},{0,-1}};
    bool safe(int i,int j,int n,int m)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    pair<int,int> bfs(vector<vector<int>>& grid,queue<pair<int,int>>& q,int fresh)
    {
        int n=grid.size();
        int m=grid[0].size();
        int min=0;
        while(!q.empty())
        {
            int k=q.size();

            while(k--)
            {
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;

                for(auto& v:direc)
                {
                    int I=i+v[0];
                    int J=j+v[1];

                    if(safe(I,J,n,m) && grid[I][J]==1)
                    {
                        grid[I][J]=2;
                        q.push({I,J});
                        fresh--;
                    }
                }
            }
            min++;
        }
        return {min,fresh};
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(fresh==0)
        {
            return 0;
        }
        auto [min,freshcount]=bfs(grid,q,fresh);

        if(freshcount==0)
        {
            return min-1;
        }
        else{
            return -1;
        }
    }
};