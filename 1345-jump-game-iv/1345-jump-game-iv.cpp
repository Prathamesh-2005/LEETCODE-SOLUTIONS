// class Solution {
// public:
//     int solve(vector<int>& arr, int i, vector<bool>& vis)
//     {
//         int n = arr.size();

//         if(i < 0 || i >= n)
//             return INT_MAX;

//         if(vis[i])
//             return INT_MAX;
            
//         if(i == n - 1)
//             return 0;
//         vis[i] = true;

//         int ans = INT_MAX;

//         int left = solve(arr, i - 1, vis);
//         if(left != INT_MAX)
//             ans = min(ans, 1 + left);

//         int right = solve(arr, i + 1, vis);
//         if(right != INT_MAX)
//             ans = min(ans, 1 + right);

//         for(int j = 0; j < n; j++)
//         {
//             if(j != i && arr[j] == arr[i] && !vis[j])
//             {
//                 int curr = solve(arr, j, vis);

//                 if(curr != INT_MAX)
//                     ans = min(ans, 1 + curr);
//             }
//         }

//         vis[i] = false;

//         return ans;
//     }

//     int minJumps(vector<int>& arr)
//     {
//         vector<bool> vis(arr.size(), false);

//         return solve(arr, 0, vis);
//     }
// };

class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if(n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int curr = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                int i = q.front();
                q.pop();

                if(i == n - 1)
                    return curr;

                if(i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = true;
                    q.push(i - 1);
                }

                if(i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = true;
                    q.push(i + 1);
                }

                for(auto idx : mp[arr[i]]) {

                    if(!vis[idx]) {
                        vis[idx] = true;
                        q.push(idx);
                    }
                }

                mp[arr[i]].clear();
            }

            curr++;
        }

        return -1;
    }
};