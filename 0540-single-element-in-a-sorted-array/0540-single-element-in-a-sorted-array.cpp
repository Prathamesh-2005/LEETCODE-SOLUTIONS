class Solution {
public:
    int counts(vector<int>&nums,int target)
    {
      int n=nums.size();
      int first=-1;
      int last=-1;

        int l=0;
        int h=n-1;

        while(l<=h)
        {
            int m=l+(h-l)/2;

            if(nums[m]==target)
            {
                first=m;
                h=m-1;
            }
            else if(nums[m]<target)
            {
                l=m+1;
            }
            else 
            {
                h=m-1;
            }
        }
       
       l=0;
       h=n-1;
          while(l<=h)
        {
            int m=l+(h-l)/2;

            if(nums[m]==target)
            {
                last=m;
                l=m+1;
            }
            else if(nums[m]<target)
            {
                l=m+1;
            }
            else 
            {
                h=m-1;
            }
        }
        return last-first+1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int cnt=counts(nums,nums[i]);
           if(cnt==1)
           {
            return nums[i];
           }
        }
        return -1;
    }
};