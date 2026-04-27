class Solution {
public:
    typedef pair<int,int>p;
    // vector<vector<int>>direc={{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
    vector<vector<vector<int>>> direc = {
    {},
    {{0, -1}, {0, 1}},    
    {{-1, 0}, {1, 0}},     
    {{0, -1}, {1, 0}},     
    {{0, 1}, {1, 0}},      
    {{0, -1}, {-1, 0}},    
    {{0, 1}, {-1, 0}} 
};
    bool safe(int i,int j,int n,int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<p>q;
        q.push({0,0});
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vis[0][0]=true;
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();

            int i=curr.first;
            int j=curr.second;

            if(i==n-1 && j==m-1)
            {
                return true;
            }

            for(auto& d:direc[grid[i][j]])
            {
                int I=i+d[0];
                int J=j+d[1];
                if(!safe(I,J,n,m) || vis[I][J] )
                {
                    continue;
                }

                for(auto& vec:direc[grid[I][J]])
                {
                    if(I+vec[0]==i && J+vec[1]==j)
                    {
                        vis[I][J]=true;
                        q.push({I,J});
                        break;
                    }
                }
            }
        }

        return false;
    }
};