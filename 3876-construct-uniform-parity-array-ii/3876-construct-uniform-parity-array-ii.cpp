class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        int mn=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            if(num&1)
            {
                cnt2++;
                if(mn<num)
                {
                    mn=num;
                    idx=i;
                }
            }else{
                cnt1++;
            }
        }

        if(cnt1==n || cnt2==n)
        {
            return true;
        }
        for(auto x:nums){
            if(x&1) mn = min(mn,x);
        }

        for(auto x:nums){
            if(!(x&1) && x-mn<1) return false;
        }
        return true;
    }
};