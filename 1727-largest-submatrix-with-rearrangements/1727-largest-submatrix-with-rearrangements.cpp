class Solution {
public:
    int solve(vector<int>& prefix,int m)
    {
        vector<int>temp=prefix;
        sort(temp.begin(),temp.end(),greater<int>());
        int ans{0};
        for(int i=0;i<m;i++)
        {
            int area=temp[i]*(i+1);
            ans=max(ans,area);
        }
        return ans;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int>prefix(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    prefix[j]+=1;
                }else{
                    prefix[j]=0;
                }
            }
            ans=solve(prefix,m);
        }
        return ans;
    }
};