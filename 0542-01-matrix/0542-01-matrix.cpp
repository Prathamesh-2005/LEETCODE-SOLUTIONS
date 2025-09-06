typedef pair<int,int>p;
class Solution {
public:
    vector<vector<int>>direc={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        queue<p>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(graph[i][j]==0)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        // queue<p>q;

        while(!q.empty())
        {
            int k=q.size();

            while(k--)
            {
                auto node=q.front();
                q.pop();
                int i=node.first;
                int j=node.second;

                for(auto& v:direc)
                {
                    int I=v[0]+i;
                    int J=v[1]+j;

                    if(I>=0 && I<n && J>=0 && J<m  && ans[I][J]==-1)
                    {
                        ans[I][J]=ans[i][j]+1;
                        q.push({I,J});
                    }
                }
            }
        }
        return ans;
    }
};