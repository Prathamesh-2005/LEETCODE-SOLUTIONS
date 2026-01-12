class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            mp.clear();
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                mp[nums[j]]++;
                if(mp.find(sum)!=mp.end())
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};