class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans(n+1,INT_MAX);
        pq.push({0,k});
        ans[k]=0;
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            mp[u].push_back({v,wt});
        }

        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            int node=p.second;
            int dist=p.first;

            if(dist>ans[node])
            {
                continue;
            }

            for(auto& v:mp[node])
            {
                int d=v.second;
                int adjnode=v.first;
                
                if(d+dist<ans[adjnode])
                {
                    ans[adjnode]=d+dist;
                    pq.push({d+dist,adjnode});
                }
            }
        }
        int mx=*max_element(ans.begin()+1,ans.end());

        return mx!=INT_MAX ? mx : -1;
    }
};