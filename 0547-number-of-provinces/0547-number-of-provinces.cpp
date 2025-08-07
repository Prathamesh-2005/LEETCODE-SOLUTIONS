class Solution {
public:
    // void dfs(int u,vector<vector<int>>& adj,vector<bool>& visited)
    // {
    //     if(visited[u]==true)
    //     {
    //         return ;
    //     }
    //     visited[u]=true; 

    //     for(int v=0;v<adj.size();v++)
    //     {
    //         if(adj[u][v]==1 && !visited[v])
    //         {
    //             dfs(v,adj,visited);
    //         }
    //     }
    // }

    void bfs(int u,vector<vector<int>>& adj,vector<bool>& visited)
    {
       queue<int>q;
       q.push(u);
       visited[u]=true;

       while(!q.empty())
       {
         int f=q.front();
         q.pop();

         for(int v=0;v<adj.size();v++)
         {
            if(!visited[v] && adj[u][v]==1)
            {
                bfs(v,adj,visited);
            }
         }
       }

    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>visited(n,false);

        int ans=0;

        for(int i=0;i<n;i++)
        {
             if(!visited[i])
             {
                bfs(i,adj,visited);
                ans++;
             }
        }
        return ans;
    }
};