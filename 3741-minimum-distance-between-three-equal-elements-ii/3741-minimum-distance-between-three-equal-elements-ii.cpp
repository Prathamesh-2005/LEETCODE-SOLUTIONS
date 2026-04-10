class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }

        for(auto& it:mp)
        {
            vector<int>v=it.second;
            if(v.size()<3)
            {
                continue;
            }

            for(int i=0;i+2<v.size();i++)
            {
                ans=min(ans,2*(v[i+2]-v[i]));
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};