class Solution {
public:
    vector<vector<int>>direc={{-1,0},{0,-1},{1,0},{0,1}};
    bool safe(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>ans;
        vector<vector<int>>grid(n,vector<int>(m,0));

        queue<pair<int,int>>q;

        
        for(int i=0;i<sources.size();i++)
        {
            for(int j=0;j<sources[0].size();j++)
            {
                q.push({i,j});
                grid[i][j]=sources[i][j];
            }
        }
        while(!q.empty())
        {
            int k=q.size();

            while(k--)
            {
                auto p=q.front();
                q.pop();
                int i_=p.first;
                int j_=p.second;
                int col=grid[i_][j_];

                for(auto& dir:direc)
                {
                    int I=i_+dir[0];
                    int J=j_+dir[1];

                    if(safe(I,J,n,m))
                    {
                        if(grid[I][J]==1 && col==2)
                        {
                            grid[I][J]=2;
                        }
                        grid[I][J]=col;
                    }
                    q.push({I,J});
                }
            }
        }
        return grid;
    }
};