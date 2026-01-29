#define ll long long 
class Solution {
public:
    ll solve(char c1,char c2 ,unordered_map<char,vector<pair<char,int>>>& mp)
    {
        vector<int>ans(26,INT_MAX);
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        ans[c1-'a']=0;
        pq.push({0,c1});

        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            char ch=top.second;
            int dist=top.first;
            if(dist > ans[ch - 'a']) continue;
            for(auto& vec:mp[ch])
            {
                int node=vec.first;
                int d=vec.second;

                if(d+dist<ans[node-'a'])
                {
                    ans[node-'a']=d+dist;
                    pq.push({d+dist,node});
                }
            }
        }

        return ans[c2-'a'];
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        ll ans=0;

        unordered_map<char,vector<pair<char,int>>>mp;

        for(int i=0;i<n;i++)
        {
            char u=original[i];
            char v=changed[i];
            int w=cost[i];
            mp[u].push_back({v,w});
        }

        for(int i=0;i<source.size();i++)
        {
            if(source[i]==target[i])
            {
                continue;
            }
            ll curr=solve(source[i],target[i],mp);
            if(curr==INT_MAX)
            {
                return -1;
            }
            ans+=curr;
        }

        return ans;
    }
};