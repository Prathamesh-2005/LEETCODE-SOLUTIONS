class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            int temp=0;
            if(nums[i]+nums[i+1]>nums[i+2])
            {
                temp=nums[i]+nums[i+1]+nums[i+2];
                ans=max(ans,temp);
            }
        }

        return ans;
    }
};