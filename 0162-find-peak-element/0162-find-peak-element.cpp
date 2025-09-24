class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int n=nums.size();

        while(l<=h)
        {
            int m=l+(h-l)/2;

            if(m>0 && m<n-1)
            {
                if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
                {
                    return m;
                }
                else if(nums[m-1]>nums[m])
                {
                   h=m-1;
                }
                else
                {
                   l=m+1;
                }
            }
            else if(m==0)
            {
                if(n==1 || nums[0]>nums[1])
                {
                    return 0;
                }
                else 
                {
                    return 1;
                }
            }
            else if(m==n-1)
            {
                if(nums[m]>nums[m-1])
                {
                    return m;
                }
                else 
                {
                    return m-1;
                }
            }
        }
        return -1;
    }
};