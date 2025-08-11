#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    void find(int n, vector<ll>& pow) {
        int i = 0;
        while (n > 0) {
            if (n & 1) 
                pow.push_back(1 << i);
            n >>= 1; 
            i++;
        }
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<int> ans;
        vector<ll> pow;
        find(n, pow);
        for (auto& v : queries) {
            int st = v[0];
            int en = v[1];
            ll temp = 1;
            for (int i = st; i <= en; i++) {
                temp =((temp*pow[i])%mod);
            }
            ans.push_back(temp % mod);
        }
        return ans;
    }
};