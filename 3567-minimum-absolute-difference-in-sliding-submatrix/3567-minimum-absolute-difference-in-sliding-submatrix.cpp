class Solution {
public:
    int find(set<int>& st)
    {
        int ans=INT_MAX;
        auto it=st.begin();
        auto prev=it;
        it++;

        while(it!=st.end())
        {
            ans=min(ans,abs(*prev-*it));
            prev=it;
            it++;
        }
        return ans;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i<=n-k;i++)
        {
            for(int j=0;j<=m-k;j++)
            {
                set<int>st;
                for(int p=i;p<i+k;p++)
                {
                    for(int q=j;q<j+k;q++)
                    {
                        st.insert(grid[p][q]);
                    }
                }
                if(st.size()==1)
                {
                    ans[i][j]=0;
                }else{
                    int ok=find(st);
                    ans[i][j]=ok;
                }
            }
        }
        return ans;
    }
};