class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y)
        {
            return;
        }
        else if (rank[parent_x] > rank[parent_y])
        {
            parent[parent_y] = parent_x;
        }
        else if (rank[parent_x] < rank[parent_y])
        {
            parent[parent_x] = parent_y;
        }
        else
        {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    int intersect(unordered_set<int>& st1,unordered_set<int>& st2,int k)
    {
        int cnt = 0;

        for (auto& num : st1)
        {
            if (st2.find(num) != st2.end())
            {
                cnt++;
                if (cnt >= k)
                {
                    return cnt;   
                }
            }
        }
        return cnt;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k)
    {
        int n = properties.size();

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        vector<unordered_set<int>> sets(n);
        for (int i = 0; i < n; i++)
        {
            for (int num : properties[i])
            {
                sets[i].insert(num);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (min(sets[i].size(), sets[j].size()) < k)
                {
                    continue;
                }

                if (sets[i].size() < sets[j].size())
                {
                    if (intersect(sets[i], sets[j], k) >= k)
                    {
                        Union(i, j);
                    }
                }
                else
                {
                    if (intersect(sets[j], sets[i], k) >= k)
                    {
                        Union(i, j);
                    }
                }
            }
        }

        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(find(i));
        }

        return st.size();
    }
};