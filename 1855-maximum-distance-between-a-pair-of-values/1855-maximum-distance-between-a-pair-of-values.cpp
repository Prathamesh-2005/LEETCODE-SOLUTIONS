class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;

        int n=nums1.size();
        int m=nums2.size();

        for(int i=0;i<n;i++)
        {
            int l=i;
            int h=m-1;
            int tar=nums1[i];
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                
                if(tar<=nums2[mid])
                {
                    ans=max(ans,mid-i);
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
        return ans;
    }
};