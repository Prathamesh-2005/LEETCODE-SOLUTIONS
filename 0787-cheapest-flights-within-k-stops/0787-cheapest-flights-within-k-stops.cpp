class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto &f : flights) {
            mp[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, 0});

        vector<vector<int>> ans(n, vector<int>(k+2, INT_MAX));
        ans[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, node, steps] = pq.top();
            pq.pop();

            if (node == dst) return cost;
            if (steps > k) continue; 

            for (auto &[next, wt] : mp[node]) {
                int newcost = cost + wt;
                if (newcost < ans[next][steps+1]) {
                    ans[next][steps+1] = newcost;
                    pq.push({newcost, next, steps+1});
                }
            }
        }

        return -1;
    }
};
