class Solution {
public:
    vector<int>rank;
    vector<int>parent;
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
        else if(rank[parent_x]<rank[parent_y])
        {
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(),parent.end(),0);
        if(connections.size()<n-1)
        {
            return -1;
        }
        int compo=n;

        for(auto &v:connections)
        {
            int f=v[0];
            int s=v[1];
            int parent_f=find(f);
            int parent_s=find(s);

            if(parent_f==parent_s)
            {
                continue;
            }
            else
            {
                Union(f,s);
                compo--;
            }
        }
        return compo-1;
    }
};