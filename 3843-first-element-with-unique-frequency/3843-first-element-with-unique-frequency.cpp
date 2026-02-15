class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=-1;

        for(auto& num:nums)
        {
            mp[num]++;
        }
        unordered_map<int,int>mp2;

        for(auto& m:mp)
        {
            mp2[m.second]++;
        }

        for(auto& num:nums)
        {
            if(mp2[mp[num]]==1)
            {
                return num;
            }
        }
        return ans;
    }
};