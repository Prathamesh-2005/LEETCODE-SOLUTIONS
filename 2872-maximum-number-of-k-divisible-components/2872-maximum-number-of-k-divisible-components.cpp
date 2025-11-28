class Solution {
public:
void dfs(int node, int parent, vector<int>& values,
         unordered_map<int,vector<int>>& mp, int& ans, int k, long long& sum)
{
    sum = values[node];

    for(int child : mp[node]) {
        if(child != parent) {
            long long childsum = 0;
            dfs(child, node, values, mp, ans, k, childsum);
            sum += childsum;
        }
    }

    if(sum % k == 0) ans++; 
}

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    unordered_map<int,vector<int>> mp;
    for(auto &e : edges){
        mp[e[0]].push_back(e[1]);
        mp[e[1]].push_back(e[0]);
    }

    int ans = 0;
    long long total = 0;
    dfs(0, -1, values, mp, ans, k, total);
    return ans;
}
};
