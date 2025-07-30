class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mxm=nums[0];
        for(auto num: nums)
        {
            if(num>mxm)
            {
                mxm=num;
            }
        }
        int count=0;
        int ans=1;

        for(auto  num:nums)
        {
            if(num==mxm)
            {
                count++;

            }
            else {count=0;}

            ans=max(ans,count);


        }
        return ans;
    }
};
