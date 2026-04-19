class Solution {
public:
    vector<vector<int>> direc = {{-1,0},{0,-1},{1,0},{0,1}};
    bool safe(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> ans;

        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        for(auto& vec : sources)
        {
            int i = vec[0];
            int j = vec[1];
            int col = vec[2];

            grid[i][j] = max(grid[i][j], col);
        }

        for(auto& vec : sources)
        {
            int i = vec[0];
            int j = vec[1];

            if(grid[i][j] == vec[2])
                q.push({i,j});
        }

        while(!q.empty())
        {
            int k = q.size();

            map<pair<int,int>,int> mp;  

            while(k--)
            {
                auto p = q.front();
                q.pop();

                int i_ = p.first;
                int j_ = p.second;
                int col = grid[i_][j_];

                for(auto& dir : direc)
                {
                    int I = i_+dir[0];
                    int J = j_+dir[1];

                    if(safe(I,J,n,m) && grid[I][J] == 0)
                    {
                        mp[{I,J}] = max(mp[{I,J}], col);
                    }
                }
            }

            for(auto &it : mp)
            {
                int I = it.first.first;
                int J = it.first.second;
                int col = it.second;

                grid[I][J] = col;
                q.push({I,J});
            }
        }

        return grid;
    }
};