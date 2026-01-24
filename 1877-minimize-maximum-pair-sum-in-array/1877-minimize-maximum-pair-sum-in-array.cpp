class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());

        int i=0,j=n-1;

        while(i<j)
        {
            int sum=nums[i]+nums[j];
            i++;
            j--;
            ans=max(ans,sum);
        }
        return ans;
    }
};