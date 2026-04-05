class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long, int> mp;
        vector<int> ans;

        for(long long i = 1; i*i*i <= n; i++) {
            for(long long j = i; j*j*j <= n; j++) {

                long long x = i*i*i + j*j*j;

                if(x > n) break;

                mp[x]++;

                if(mp[x] == 2) {
                    ans.push_back((int)x);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};