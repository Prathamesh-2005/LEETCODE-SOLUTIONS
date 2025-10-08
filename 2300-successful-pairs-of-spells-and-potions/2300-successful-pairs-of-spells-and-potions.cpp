#define ll long long 
class Solution {
public:
    int solve(int spell,vector<int>& potions,ll success)
    {
        int ans=0;
        ll num = (success + spell - 1) / spell;
        auto it=lower_bound(potions.begin(),potions.end(),num);
        ans=potions.end()-it;
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
          int n=spells.size();
          int m=potions.size();

          vector<int>ans(n,0);
          sort(potions.begin(),potions.end());
          for(int i=0;i<n;i++)
          {
              int okay=0;
              okay=solve(spells[i],potions,success);
              ans[i]=okay;
          }

          return ans;
    }
};