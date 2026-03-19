class Solution {
public:
    typedef pair<int,int> p;
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<p>>pref(n,vector<p>(m,{0,0}));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=0,y=0;
                if(grid[i][j]=='X')
                {
                    x++;
                }
                else if(grid[i][j]=='Y'){
                    y++;
                }

                if(i>0)
                {
                    x+=pref[i-1][j].first;
                    y+=pref[i-1][j].second;
                }
                if(j>0)
                {
                    x+=pref[i][j-1].first;
                    y+=pref[i][j-1].second;
                }
                if(i>0 && j>0)
                {
                    x-=pref[i-1][j-1].first;
                    y-=pref[i-1][j-1].second;
                }
                pref[i][j].first=x;
                pref[i][j].second=y;

                if(x==y && x>=1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};