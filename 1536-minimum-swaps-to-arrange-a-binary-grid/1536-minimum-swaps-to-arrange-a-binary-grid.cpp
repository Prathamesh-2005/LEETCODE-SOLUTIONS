class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>vec(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int j=n-1;
            int cnt=0;
            while(j>=0 && grid[i][j]==0)
            {
                j--;
                cnt++;
            }
            vec[i]=cnt;
        }
        
        for(int i=0;i<n;i++)
        {
            int req=n-i-1;
            int j=i;

            while(j<n && vec[j]<req)
            {
                j++;
            }
            if(j>=n)
            {
                return -1;
            }
            ans+=(j-i);

            while(j>i)
            {
                swap(vec[j],vec[j-1]);;
                j--;
            }
        }
        return ans;
    }
};