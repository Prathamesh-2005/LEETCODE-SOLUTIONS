class Solution {
public:
    bool dfs(vector<vector<int>>& adj,int currcolor,vector<int>& color,int u)
    {
        color[u]=currcolor;

        for(int& v:adj[u])
        {
            if(color[v]==currcolor)
            {
                return false;
            }
            if(color[v]==-1)
            {
                int ColorOfV=1-currcolor;
                if(dfs(adj,ColorOfV,color,v)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(graph,1,color,i)==false)
                  return false;
            }
        }
        return true;
    }
};