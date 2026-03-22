class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]&1)
            {
                cnt2++;
            }else{
                cnt1++;
            }
        }

        if(cnt1==n || cnt2==n)
        {
            return true;
        }
        if(cnt1>0 && cnt2>0)
        {
            return  true;
        }
        return false;
    }
};