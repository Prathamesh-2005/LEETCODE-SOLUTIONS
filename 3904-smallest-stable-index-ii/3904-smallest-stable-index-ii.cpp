class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>mx(n,0);
        vector<int>mn(n,0);
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                mx[i]=max(mx[i-1],nums[i]);
            }else
            {
                mx[i]=nums[i];
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(i!=n-1)
            {
                mn[i]=min(mn[i+1],nums[i]);
            }else{
                mn[i]=nums[i];
            }
        }

        for(int i=0;i<n;i++)
        {
            int curr=mx[i]-mn[i];
            if(curr<=k)
            {
                ans=min(ans,i);
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};