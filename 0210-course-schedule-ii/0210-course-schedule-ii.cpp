class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>in(numCourses,0);
        unordered_map<int,vector<int>>mp;
        int count=0;
        queue<int>q;
        for(auto&  v:prerequisites)
        {
            int a=v[0];
            int b=v[1];
            mp[b].push_back(a);
            in[a]++;
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
                count++;
            }
        }

        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int &v:mp[u])
            {
                in[v]--;
                if(in[v]==0)
                {
                    q.push(v);
                    count++;
                }
            }
        }
        if(count!=numCourses)
        {
            return {};
        }
        return ans;

    }
};