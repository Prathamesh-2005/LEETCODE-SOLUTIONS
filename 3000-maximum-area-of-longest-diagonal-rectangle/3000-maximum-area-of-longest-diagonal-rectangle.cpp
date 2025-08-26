#define d double 
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        int n=dimensions.size();
        d dig=-1;
        d curr=INT_MIN;
        int idx;
        for(int i=0;i<n;i++)
        {
            curr=sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
            if(curr>=dig)
            {
                idx=i;
                dig=curr;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(idx==i)
            {
                ans=dimensions[i][0]*dimensions[i][1];
            }
        }
        return ans;
    }
};