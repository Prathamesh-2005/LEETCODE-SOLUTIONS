class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>pref(n,vector<int>(m,0));
    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum=grid[i][j];
                sum+=(i>0 ? pref[i-1][j] : 0);
                sum+=(j>0 ? pref[i][j-1] : 0);
                sum-=(i>0 && j>0 ? pref[i-1][j-1] : 0);
                pref[i][j]=sum;

                if(pref[i][j]<=k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};