class Solution {
public:
    typedef long long ll;
    ll solve(int i,int j,vector<int>& rob,vector<int>& factory,vector<vector<ll>>& dp)
    {
        if(i>=rob.size())
        {
            return 0;
        }
        if(j>=factory.size())
        {
            return 1e15;
        }
        if(dp[i][j]!=-1)
        {

            return dp[i][j];
        }
        ll tk=abs(rob[i]-factory[j])+solve(i+1,j+1,rob,factory,dp);
        ll ntk=0+solve(i,j+1,rob,factory,dp);

        return dp[i][j]=min(tk,ntk);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ll ans=0;
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>tmp;
        int n=robot.size();
        for(auto& fac:factory)
        {
            for(int i=0;i<fac[1];i++)
            {
                tmp.push_back(fac[0]);
            }
        }
        int m=tmp.size();
        vector<vector<ll>>dp(n,vector<ll>(m,-1));
        return solve(0,0,robot,tmp,dp);
    }
};