#define ll long long 
class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y)
    {
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x==parent_y)
        {
            return ;
        }
        if(rank[parent_x]>rank[parent_y])
        {
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_y]>rank[parent_x])
        {
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        iota(parent.begin(),parent.end(),0);
        ll ans=0;
        for(auto &vec:edges)
        {
            int u=vec[0];
            int v=vec[1];
            Union(u,v);
        }

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            int parents=find(i);
            mp[parents]++;
        }
        ll remain=n;
    
        //ans=size*(remain-size);
        for(auto& m:mp)
        {
            int nodes=m.second;
            ans+=nodes*(remain-nodes);
            remain-=nodes;
        }
        return ans;
    }
};