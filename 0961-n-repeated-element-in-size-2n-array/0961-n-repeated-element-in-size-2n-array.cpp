class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int m=nums.size();
        int n=m/2;
        int ans=0;
        unordered_map<int,int>mp;
        for(auto num:nums)
        {
            mp[num]++;
        }

        for(auto& m:mp)
        {
            if(m.second==n)
            {
                ans=m.first;
            }
        }
        return ans;
    }
};