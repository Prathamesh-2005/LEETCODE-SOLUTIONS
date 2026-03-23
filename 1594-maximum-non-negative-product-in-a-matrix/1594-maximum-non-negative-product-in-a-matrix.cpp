class Solution {
public:
    int mod=1e9+7;
    typedef  long long ll;
    pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid,ll prod,int n,int m)
    {
        if(i==n-1 && j==m-1)
        {
            return {grid[i][j],grid[i][j]};
        }
        if(i>=n || j>=m)
        {
            return {LLONG_MIN,LLONG_MAX};
        }
        auto right=solve(i,j+1,grid,prod*grid[i][j],n,m);
        auto down=solve(i+1,j,grid,prod*grid[i][j],n,m);
        ll mx=LLONG_MIN;
        ll mn=LLONG_MAX;

        vector<ll>tmp;
        if(right.first!=LLONG_MIN)
        {
            tmp.push_back(right.first*grid[i][j]);
            tmp.push_back(right.second*grid[i][j]);
        }

        if(down.first!=LLONG_MIN)
        {
            tmp.push_back(down.first*grid[i][j]);
            tmp.push_back(down.second*grid[i][j]);
        }
        mx=*max_element(tmp.begin(),tmp.end());
        mn=*min_element(tmp.begin(),tmp.end());

        return {mx,mn};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        auto ans= solve(0,0,grid,1,n,m); 

        if(ans.first<0)
        {
            return -1;
        }

        return ans.first%mod;   
    }
};