class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                int j=nums[i]%n;
                ans[i]=nums[(i+j)%n];
            }
            else if(nums[i]<0)
            {
                int j=abs(nums[i])%n;
                int idx=(i-j+n)%n;
                ans[i]=nums[idx];
            }
            else if(nums[i]==0)
            {
                ans[i]=nums[i];
            }
        }
        return ans;
    }
};