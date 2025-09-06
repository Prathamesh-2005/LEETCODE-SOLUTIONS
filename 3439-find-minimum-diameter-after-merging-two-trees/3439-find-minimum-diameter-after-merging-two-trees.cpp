class Solution {
public:
    unordered_map<int,vector<int>> build(vector<vector<int>>& edges)
    {
        unordered_map<int,vector<int>>adj;

        for(auto& edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    pair<int,int> bfs(unordered_map<int,vector<int>>& adj,int node)
    {
        unordered_map<int,bool>visited;
        visited[node]=true;
        queue<int>q;
        q.push(node);
        int farthest=0;
        int dist=0;

        while(!q.empty())
        {
            int n=q.size();

            while(n--)
            {
                int curr=q.front();
                q.pop();
                farthest=curr;

                for(auto& nbr:adj[curr])
                {
                    if(!visited[nbr])
                    {
                        visited[nbr]=true;
                        q.push(nbr);
                    }
                }
            }

            if(!q.empty())
            {
                dist++;
            }
        }
        return {farthest,dist};
    }
    int find(unordered_map<int,vector<int>>& adj)
    {
        auto [farthest,dist]=bfs(adj,0);

        auto [otherEnd,diameter]=bfs(adj,farthest);

        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>adj1=build(edges1);
        unordered_map<int,vector<int>>adj2=build(edges2);

        int d1=find(adj1);
        int d2=find(adj2);

        int temp = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1,d2,temp});
    }
};