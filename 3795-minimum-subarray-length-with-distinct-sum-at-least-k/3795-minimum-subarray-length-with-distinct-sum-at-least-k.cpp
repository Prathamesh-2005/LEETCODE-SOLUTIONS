class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;

        int i=0,j=0;
        unordered_map<int,int>mp;
        int sum=0;
        
        while(j<n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]==1)
            {
                sum+=nums[j];
            }

            while(sum>=k)
            {
                ans=min(ans,j-i+1);
                mp[nums[i]]--;

                if(mp[nums[i]]==0)
                {
                    sum-=nums[i];
                }
                i++;
            }
            j++;
        }

        return ans==INT_MAX ? -1 : ans;
    }
};