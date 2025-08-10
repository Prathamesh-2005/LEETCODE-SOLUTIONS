class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
           int n=fruits.size();
           int ans=0;
        vector<bool>used(n,false);
           for(int i=0;i<n;i++)
           {
             for(int j=0;j<n;j++)
             {
                if(!used[j] && fruits[i]<=baskets[j])
                {
                    used[j]=true;
                    break;
                }
             }
           }
           for(int i=0;i<n;i++)
           {
            if(used[i]==false)
            {
                ans++;
            }
           }
           return ans;
    }
};