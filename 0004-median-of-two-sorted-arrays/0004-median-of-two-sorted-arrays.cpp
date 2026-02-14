class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        int m=nums1.size();
        int n=nums2.size();
        int l=0,h=m;

        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int right=(m+n+1)/2-mid;

            int x1=(mid==0 ? INT_MIN : nums1[mid-1]);
            int x2=(right==0 ? INT_MIN : nums2[right-1]);
            int x3=(mid==m ? INT_MAX : nums1[mid]);
            int x4=(right==n ? INT_MAX : nums2[right]);

            if(x1<=x4 && x2<=x3)
            {
                if((m+n)%2==1)
                {
                    return max(x1,x2);
                }else{
                    return (max(x1,x2)+min(x3,x4))/2.0;
                }
            }
            if(x1>x4)
            {
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
    }
};