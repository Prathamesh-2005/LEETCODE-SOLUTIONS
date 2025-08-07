class Solution {
public:
    bool kahn(int n,unordered_map<int,vector<int>>& mp,vector<int>& in)
    {
        int count=0;
        queue<int>q;

        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                count++;
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(int& v:mp[u])
            {
               in[v]--;
               if(in[v]==0)
               {
                 q.push(v);
                 count++;
               }
            }
        }
        if(count==n)
        {
            return true;
        }
        else return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        unordered_map<int,vector<int>>adj;
        vector<int>in(numCourses,0);

        for(auto& v:prerequisites)
        {
            int a=v[0];
            int b=v[1];
            adj[b].push_back(a);
            in[a]++;
        }
        return kahn(numCourses,adj,in);
    }
};