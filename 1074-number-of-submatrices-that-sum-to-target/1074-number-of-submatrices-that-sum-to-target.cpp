class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }

        for(int sc=0;sc<m;sc++)
        {
            for(int j=sc;j<m;j++)
            {
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;

                for(int i=0;i<n;i++)
                {
                    sum+=matrix[i][j]-(sc>0 ? matrix[i][sc-1] : 0);

                    if(mp.find(sum-target)!=mp.end())
                    {
                        ans+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};