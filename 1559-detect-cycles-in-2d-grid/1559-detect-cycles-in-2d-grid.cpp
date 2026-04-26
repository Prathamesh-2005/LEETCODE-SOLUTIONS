class Solution {
public:
    typedef pair<int,int> p;

    bool safe(int i,int j,int n,int m) {
        return (i>=0 && i<n && j>=0 && j<m);
    }

    vector<vector<int>> direc={{-1,0},{0,-1},{1,0},{0,1}};

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(vis[i][j]) continue;

                queue<pair<p,p>> q;
                q.push({{i,j},{-1,-1}});
                vis[i][j] = true;

                while(!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    int x = curr.first.first;
                    int y = curr.first.second;
                    int px = curr.second.first;
                    int py = curr.second.second;

                    for(auto& d:direc) {
                        int I = x + d[0];
                        int J = y + d[1];

                        if(!safe(I,J,n,m)) continue;

                        if(grid[I][J] != grid[x][y]) continue;

                        if(!vis[I][J]) {
                            vis[I][J] = true;
                            q.push({{I,J},{x,y}});
                        }
                        else if(I != px || J != py) {
                            return true; 
                        }
                    }
                }
            }
        }
        return false;
    }
};