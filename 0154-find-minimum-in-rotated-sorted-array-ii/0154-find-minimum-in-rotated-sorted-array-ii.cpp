class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int ans=0;
        while(l<=h)
        {
            while(l<h && nums[h]==nums[h-1])
            {
                h--;
            } 
            while(h>l && nums[l]==nums[l+1])
            {
                l++;
            }
            int mid=l+(h-l)/2;
            if(nums[mid]<nums[ans])
            {
                ans=mid;
            }
            if(nums[mid]>nums[h])
            {
                l=mid+1;
            }else{
                h=mid-1;
            }
        }

        return nums[ans];
    }
};