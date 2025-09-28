class Solution {
public:
    bool check(vector<int>& weights,int days,int m)
    {
         int n=weights.size();
         int count=1;
         int sum=0;
         for(int i=0;i<n;i++)
         {
            sum+=weights[i];
            if(sum>m)
            {
                count++;
                sum=weights[i];
            }
         }
         return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int res=INT_MAX;

        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(check(weights,days,m))
            {
                res=m;
                h=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return res;
    }
};