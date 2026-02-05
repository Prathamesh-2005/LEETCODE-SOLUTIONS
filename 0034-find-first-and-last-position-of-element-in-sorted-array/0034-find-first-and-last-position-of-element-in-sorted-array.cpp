class Solution {
public:
    int first(vector<int>& nums,int target)
    {
        int n=nums.size();

        int l=0;
        int h=n-1;
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                h=mid-1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }

    int second(vector<int>& nums,int target)
    {
        int n=nums.size();

        int l=0;
        int h=n-1;
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n=nums.size();
        ans[0]=first(nums,target);
        ans[1]=second(nums,target);
        return ans;
    }
};