class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        int j=n-1;

        while(i<n-1 && nums[i]<=nums[i+1])
        {
            i++;
        }
        if(i==n-1)
        {
            return 0;
        }
        while(j>0 && nums[j]>=nums[j-1])
        {
            j--;
        }
        int mx=INT_MIN;
        int mn=INT_MAX;

        for(int k=i;k<=j;k++)
        {
            mn=min(mn,nums[k]);
            mx=max(mx,nums[k]);
        }
        while(i>0 && nums[i-1]>mn)
        {
            i--;
        }

        while(j<n-1 && nums[j+1]<mx)
        {
            j++;
        }
        return j-i+1;
    }
};