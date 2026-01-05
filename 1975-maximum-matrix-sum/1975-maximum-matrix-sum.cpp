#define ll long long 
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        ll ans=0;
        ll sum=0,cnt=0;
        int small=INT_MAX;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0)
                {
                    cnt++;
                }
                if(abs(matrix[i][j])<small)
                {
                    small=abs(matrix[i][j]);
                }
            }
        }

        if(cnt%2==0)
        {
            return sum;
        }

        return sum-2*abs(small);
    }
};