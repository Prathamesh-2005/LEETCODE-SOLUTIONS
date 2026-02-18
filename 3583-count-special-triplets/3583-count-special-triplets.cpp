class Solution {
public:
    typedef long long ll;
    int specialTriplets(vector<int>& nums) {
        ll mod=1e9+7;
        int n=nums.size();
        ll ans=0;
        unordered_map<ll,ll>mp1,mp2;

        for(auto& num:nums)
        {
            mp2[num]++;
        }

        for(auto& num:nums)
        {
            mp2[num]--;
            ll tar=num*2;
            ans=(ans+(mp1[tar]*mp2[tar])%mod)%mod;
            mp1[num]++;
        }
        return ans%mod;
    }
};