class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n),left(n),right(n);
        int sum=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++)
        {
            left[i]=sum;
            sum+=nums[i];
            right[i]=total-sum;
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=abs(right[i]-left[i]);
        }
        return ans;
    }
};