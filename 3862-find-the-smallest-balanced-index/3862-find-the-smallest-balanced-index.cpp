class Solution {
public:
    typedef long long ll;
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        ll sum=accumulate(nums.begin(),nums.end(),0ll);
        ll prod=1;

        for(int i=n-1;i>=0;i--)
        {
            sum-=nums[i];
            if(sum==prod)
            {
                return i;
            }
            if(prod>sum)
            {
                break;
            }
            if(prod>1e19/nums[i])
            {
                break;
            }
            prod*=nums[i];
        }
        return -1;
    }
};