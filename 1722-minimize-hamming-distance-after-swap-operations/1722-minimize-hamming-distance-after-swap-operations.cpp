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
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent)
        {
            return ;
        }
        if(rank[x_parent]<rank[y_parent])
        {
            parent[x_parent]=y_parent;
        }
        else if(rank[y_parent]<rank[x_parent])
        {
            parent[y_parent]=x_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(int i=0;i<allowedSwaps.size();i++)
        {
            Union(allowedSwaps[i][0],allowedSwaps[i][1]);
        }

        unordered_map<int,unordered_map<int,int>>mp;

        for(int i=0;i<n;i++)
        {
            int parent=find(i);
            mp[parent][source[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int parent=find(i);
            if(mp[parent][target[i]]>0)
            {
                mp[parent][target[i]]--;
            }else{
                ans++;
            }
        }
        return ans;
    }
};