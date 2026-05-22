class Solution {
public:
    int find(vector<int>& nums)
    {
        int n=nums.size();
        int l=0;
        int h=n-1;

        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]>nums[h])
            {
                l=mid+1;
            }else{
                h=mid;
            }
        }
        return l;
    
    }

    int b_search(vector<int>& nums,int target,int l,int h)
    {
        int n=nums.size();

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(nums[mid]==target)
            {
                return mid;
            }else if(nums[mid]<target)
            {
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=-1;

        int mini=find(nums);
        int left=b_search(nums,target,0,mini-1);

        int right=b_search(nums,target,mini,n-1);

        if(left!=-1)
        {
            return left;
        }else if(right!=-1)
        {
            return right;
        }
        return left;
    }
};