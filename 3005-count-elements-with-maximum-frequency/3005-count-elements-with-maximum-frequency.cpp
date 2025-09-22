class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mx=INT_MIN;
        for(auto& num:nums)
        {
            mp[num]++;
        }

        for(auto& m:mp)
        {
            mx=max(mx,m.second);
        }
        int ans=0;
        for(auto& m:mp)
        {
            if(m.second==mx)
            {
                ans+=mx;
            }
        }

        return ans;
    }
};