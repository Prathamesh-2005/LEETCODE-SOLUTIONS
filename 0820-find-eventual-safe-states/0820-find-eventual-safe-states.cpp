class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adj;
        int n=graph.size();
        vector<int>in(n,0);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            for(auto& g:graph[i])
            {
                adj[g].push_back(i);
                in[i]++;
            }
        }
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto& v:adj[node])
            {
                in[v]--;

                if(in[v]==0)
                {
                    q.push(v);
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};