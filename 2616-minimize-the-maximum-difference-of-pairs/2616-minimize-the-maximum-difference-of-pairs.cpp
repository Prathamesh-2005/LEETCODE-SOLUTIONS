class Solution {
public:
    bool check(int mid,vector<int>& nums,int p)
    {
        int cnt=0;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<=mid)
            {
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int l=0;
        int h=nums[n-1]-nums[0];
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(mid,nums,p))
            {
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};