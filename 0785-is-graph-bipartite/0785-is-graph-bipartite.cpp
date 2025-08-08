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
    bool bfs(vector<vector<int>>& adj,int currcolor,vector<int>& color,int u)
    {
        queue<pair<int,int>>q;
        color[u]=currcolor;
        q.push({u,currcolor});

        while(!q.empty())
        {
            auto p=q.front();
            int v=p.first;
            int ColorOfV=p.second;
            q.pop();
            for(int& k:adj[v])
            {
                if(color[k]==ColorOfV)
                {
                    return false;
                }
                if(color[k]==-1)
                {
                    int newcolor=1-ColorOfV;
                    color[k]=newcolor;
                    q.push({k,newcolor});
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
                if(bfs(graph,1,color,i)==false)
                  return false;
            }
        }
        return true;
    }
};