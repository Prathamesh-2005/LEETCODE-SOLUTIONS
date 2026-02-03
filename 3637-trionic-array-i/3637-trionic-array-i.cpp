class Solution {
public:
    bool increase(int p,int q,vector<int>& nums)
    {
        int n=nums.size();
        for(int k=p+1;k<=q;k++)
        {
            if(nums[k]<=nums[k-1])
            {
                return false;
            }
        }
        return true;
    }

    bool decrease(int p,int q,vector<int>& nums)
    {
        int n=nums.size();
        for(int k=p+1;k<=q;k++)
        {
            if(nums[k]>=nums[k-1])
            {
                return false;
            }
        }
        return true;
    }
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=1;
        int q=n-2;
        while(p<q)
        {
            if(!increase(0,p,nums))
            {
                p++;
            }
            else if(!decrease(p,q,nums))
            {
                p++;
            }else if(!increase(q,n-1,nums)){
                q--;
            }else{
                return true;
            }
        }
        return false;
    }
};