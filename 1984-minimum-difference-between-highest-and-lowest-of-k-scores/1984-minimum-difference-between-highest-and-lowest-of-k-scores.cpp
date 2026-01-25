class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i+k-1<n;i++)
        {
            int mn=nums[i];
            int mx=nums[i+k-1];
            ans=min(ans,mx-mn);
        }

        return ans;

    }
};