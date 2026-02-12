class Solution {
public:
    bool check(vector<int>&nums,int k,int m)
    {
        int sum=0;
        int count=1;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]>m)
            {
                count++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];

            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);

        int res=-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;

            if(check(nums,k,m))
            {
                res=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return res;
    }
};