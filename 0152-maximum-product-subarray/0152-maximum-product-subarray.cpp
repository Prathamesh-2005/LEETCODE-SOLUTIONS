class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int curr=1;
        int mn=1;
        for(int i=0;i<n;i++)
        {
            curr=max(curr*nums[i],nums[i]);
            mn=mn*nums[i];
            ans=max({curr,ans,mn});
        }
        return ans;
    }
};